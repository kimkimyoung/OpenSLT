#include "simulator.h"
#include "logger.h"

int simulator::ms_simulatorNum=0;
std::mutex simulator::ms_simulatorNumMutex;
std::mutex simulator::ms_frameListMutex;
std::vector<std::thread *> simulator::ms_threads;

simulator::simulator(std::string ifilePath){
    m_simState=simCreated;//simulator runing state
    m_packetNum=0;//number of packets have read
    m_cmdRun=false;//0:stop;1:run
    m_pause=false;//1:paused;0:run
    dt=INIT_SPEED;
    m_ifilePath=ifilePath;//simulator read data from ifile
    m_frameList=std::queue<Frame*>();
    LOG(debug,"Created simulator:"+std::to_string(ms_simulatorNum));
}

simulator::~simulator(){
    decreaseSimulatorNum();
}

int simulator::initializeSimulator(){
    if(m_simState==simCreated){
        m_ifile.open(m_ifilePath,std::ios::in|std::ios::binary);
        if(!m_ifile.is_open()){
            m_simState=simFailInit;
            LOG(error,"Failed open xtf file "+m_ifilePath);
            return 0;
        }
        increaseSimulatorNum();
        LOG(debug,"Initialized simulator:"+std::to_string(ms_simulatorNum));
        m_simState=simInit;
    }
}

int simulator::startSimulator(){
    if(m_simState==simInit){
        m_cmdRun=START_SIMULATOR;
        ms_threads.push_back(new std::thread(std::bind(&simulator::runningSimulator, this)));
    }
}

int simulator::stopSimulator(){
    m_cmdRun=STOP_SIMULATOR;
    for (std::vector<std::thread*>::iterator it = ms_threads.begin(); it != ms_threads.end() ; ++it)
    {
        (*it)->join();
        delete *it;
    }
    ms_threads.clear();
    while(m_frameList.size()>=1){
        Frame* ptr=m_frameList.front();
        m_frameList.pop();
        delete ptr;
        LOG(debug,"clear m_frameList");
    }
    LOG(debug,"stop simulator.");
    return 1;
}

int simulator::pauseSimulator(){
    m_pause=true;
    LOG(debug,"simulator paused...");
    return 1;
}
int simulator::unpauseSimulator(){
    m_pause=false;
    m_condPause.notify_all();
    LOG(debug,"simulator continue...");
    return 1;
}
int simulator::speedUp(){
    dt>>=1;
    dt=fmax(dt,MAX_SPEED);
    return 1;
}
int simulator::speedDown(){
    dt<<=1;
    dt=fmin(dt,MIN_SPEED);
    return 1;
}
int simulator::setSpeed(int speed){
    dt = speed;
    return 1;
}
int simulator::getSpeed()
{
    return dt;
}
int simulator::runningSimulator(){
    xtf_packetheader packetHeader;
    LOG(debug,"Simulator is running for reading "+m_ifilePath+" as input data");
    std::unique_lock <std::mutex> lck(m_pauseMutex);
    while(m_cmdRun)//decoding machine
    {
        if(m_pause){
            m_condPause.wait(lck);
        }
        if(m_simState==simState::simInit){
            if(m_ifile.get()==0x7B){//find file header
                m_xtfFileHeader.FileFormat=0x7B;
                m_ifile.read((char *)&m_xtfFileHeader+1,sizeof(xtf_fileheader)-1);
                m_simState=simState::simHaveFileHeader;
                LOG(debug,"Have found xtf file header:\nNumberOfSonarChannels: "+std::to_string(m_xtfFileHeader.NumberOfSonarChannels)+
                    "\nNumberOfBathymetryChannels: "+std::to_string(m_xtfFileHeader.NumberOfBathymetryChannels));
                int chanNum=m_xtfFileHeader.NumberOfSonarChannels+m_xtfFileHeader.NumberOfBathymetryChannels;
                if(chanNum<=6){
                    for(int i=0;i<chanNum;i++){
                       LOG(debug,"Chaninfo["+std::to_string(i)+"] TypeOfChannel: "+std::to_string(m_xtfFileHeader.chaninfo[i].TypeOfChannel)+
                       "\nChaninfo["+std::to_string(i)+"] SubChannelNumber: "+std::to_string(m_xtfFileHeader.chaninfo[i].SubChannelNumber)+
                        "\nChaninfo["+std::to_string(i)+"] SubChannelNumber: "+std::to_string(m_xtfFileHeader.chaninfo[i].SubChannelNumber)+
                        "\nChaninfo["+std::to_string(i)+"] BytesPerSample: "+std::to_string(m_xtfFileHeader.chaninfo[i].BytesPerSample)+
                        "\nChaninfo["+std::to_string(i)+"] SamplesPerChannel: "+std::to_string(m_xtfFileHeader.chaninfo[i].SamplesPerChannel)+
                        "\nChaninfo["+std::to_string(i)+"] VoltScale: "+std::to_string(m_xtfFileHeader.chaninfo[i].VoltScale)+
                        "\nChaninfo["+std::to_string(i)+"] TiltAngle: "+std::to_string(m_xtfFileHeader.chaninfo[i].TiltAngle)+
                        "\nChaninfo["+std::to_string(i)+"] Frequency: "+std::to_string(m_xtfFileHeader.chaninfo[i].Frequency)+
                        "\nChaninfo["+std::to_string(i)+"] HorizBeamAngle: "+std::to_string(m_xtfFileHeader.chaninfo[i].HorizBeamAngle)+
                        "\nChaninfo["+std::to_string(i)+"] BeamWidth: "+std::to_string(m_xtfFileHeader.chaninfo[i].BeamWidth)
                       );
                    }
                }else{
                    LOG(debug,"Total number of channels beyond 6,quit!");
                    m_simState=simState::simStop;
                    m_cmdRun=STOP_SIMULATOR;//stop decoding machine when channel number beyond 6
                    if(m_ifile.is_open())
                        m_ifile.close();
                    continue;
                }
            }
        }
        if(m_simState==simState::simHaveFileHeader){
            memset(&packetHeader,0,sizeof(xtf_packetheader));
            m_ifile.read((char *)&packetHeader,sizeof(char)*2);
            if(packetHeader.MagicNumber==XTF_MAGIC_NUMBER){//find packet header
                LOG(debug,"Finding Magic Number: Yes");
                m_ifile.read((char*)&packetHeader+2,sizeof(xtf_packetheader)-2);
                LOG(debug,"Have found packet header:\nHeaderType: "+
                    std::string(packetHeader.HeaderType==0?"Sonar ping":
                    (packetHeader.HeaderType==1?"Annotation":
                    (packetHeader.HeaderType==2?"Bathymetry":
                    (packetHeader.HeaderType==3?"Attitude":"Unkonwn packet header type"))))+
                    "\nNumBytesThisRecord:"+std::to_string(packetHeader.NumBytesThisRecord)+
                    "\nNumChansToFollow: "+std::to_string(packetHeader.NumChansToFollow)+
                    "\nSubChannelNumber: "+std::to_string(packetHeader.SubChannelNumber)
                    );
                if(packetHeader.HeaderType==XTF_DATA_SIDESCAN){
                    LOG(debug,"Have found packet header type: Ping!");
                    m_simState=simState::simHavePing;
                }else if(packetHeader.HeaderType==XTF_DATA_BATHYMETRY){
                    LOG(debug,"Have found packet header type: Bathymetry");
                    m_simState=simState::simHaveBathmetry;
                }else if(packetHeader.HeaderType==XTF_DATA_ATTITUDE){
                    LOG(debug,"Have found packet header type: Attitude");
                    m_simState=simState::simHaveAttitude;
                }else if(packetHeader.HeaderType==XTF_HEADER_KLEINV4_DATA_PAGE){
                    LOG(debug,"Have found packet header type: KLEINV4000!");
                    m_simState=simState::simHavePing;
                }else{
                    LOG(debug,"Have found unknown packet header type!");
                    m_simState=simState::simStop;
                    m_cmdRun=STOP_SIMULATOR;//stop decoding machine when channel number beyond 6
                    if(m_ifile.is_open())
                        m_ifile.close();
                    continue;
                }
            }
        }
        if(m_simState==simState::simHavePing){
            xtf_pingpacket * p_pingPacket=new xtf_pingpacket;
            unsigned short bytesPerSample=m_xtfFileHeader.chaninfo[packetHeader.SubChannelNumber].BytesPerSample;
            memset(p_pingPacket,0,sizeof(xtf_pingpacket));
            p_pingPacket->pingHeader.packetHeader=packetHeader;
            m_ifile.read((char*)&p_pingPacket->pingHeader+sizeof(xtf_packetheader),sizeof(xtf_pingheader)-sizeof(xtf_packetheader));
            m_ifile.read((char*)&p_pingPacket->pingChanHeader[0],sizeof(xtf_pingchanheader));
            unsigned int numSamples=p_pingPacket->pingChanHeader[0].NumSamples;
            p_pingPacket->p_ping[0]=malloc(bytesPerSample*numSamples);
            memset(p_pingPacket->p_ping[0],0,bytesPerSample*numSamples);
            m_ifile.read((char*)p_pingPacket->p_ping[0],bytesPerSample*numSamples);
            LOG(debug,"Read "+std::to_string(bytesPerSample*numSamples)+"bytes to p_ping[0]");
            m_ifile.read((char*)&p_pingPacket->pingChanHeader[1],sizeof(xtf_pingchanheader));
            numSamples=p_pingPacket->pingChanHeader[1].NumSamples;
            p_pingPacket->p_ping[1]=malloc(bytesPerSample*numSamples);
            memset(p_pingPacket->p_ping[1],0,bytesPerSample*numSamples);
            m_ifile.read((char*)p_pingPacket->p_ping[1],bytesPerSample*numSamples);
            LOG(debug,"Read "+std::to_string(bytesPerSample*numSamples)+"bytes to p_ping[1]");
            LOG(debug,"Success reading a ping packet");
            m_simState=simState::simHaveFileHeader;
            ms_frameListMutex.lock();
            m_frameList.push(new pingFrame(p_pingPacket,m_xtfFileHeader));
            ms_frameListMutex.unlock();
            p_pingPacket->p_ping[0]=NULL;
            p_pingPacket->p_ping[1]=NULL;
            delete p_pingPacket;
            usleep(dt);
        }
        if(m_simState==simState::simHaveBathmetry){
            xtf_bathmetrypacket * p_bathmetryPacket=new xtf_bathmetrypacket;
            unsigned short bytesPerSample=m_xtfFileHeader.chaninfo[packetHeader.SubChannelNumber].BytesPerSample;
            unsigned int numBytes=packetHeader.NumBytesThisRecord;
            memset(p_bathmetryPacket,0,sizeof(xtf_bathmetrypacket));
            p_bathmetryPacket->bathmetryHeader.packetHeader=packetHeader;
            m_ifile.read((char*)&p_bathmetryPacket->bathmetryHeader+sizeof(xtf_packetheader),sizeof(xtf_pingheader)-sizeof(xtf_packetheader));
            p_bathmetryPacket->p_bathmetry=malloc(numBytes-sizeof(xtf_pingheader));
            memset(p_bathmetryPacket->p_bathmetry,0,numBytes-sizeof(xtf_pingheader));
            m_ifile.read((char*)p_bathmetryPacket->p_bathmetry,numBytes-sizeof(xtf_pingheader));
            LOG(debug,"Success reading a bathmetry packet: "+
                std::string("\nPacket header length: ")+std::to_string(sizeof(xtf_pingheader))+
                std::string("\nPacket data length: ")+std::to_string(numBytes-sizeof(xtf_pingheader)));
            m_simState=simState::simHaveFileHeader;
            ms_frameListMutex.lock();
            m_frameList.push(new bathmetryFrame(p_bathmetryPacket,m_xtfFileHeader));
            ms_frameListMutex.unlock();
            p_bathmetryPacket->p_bathmetry=NULL;
            delete p_bathmetryPacket;
        }
        if(m_simState==simState::simHaveAttitude){
            xtf_attitudeheader * p_attitudePacket=new xtf_attitudeheader;
            memset(p_attitudePacket,0,sizeof(xtf_attitudeheader));
            p_attitudePacket->packetHeader=packetHeader;
            m_ifile.read((char*)&p_attitudePacket+sizeof(xtf_packetheader),sizeof(xtf_attitudeheader)-sizeof(xtf_packetheader));
            LOG(debug,"Success reading an attitude packet: "+std::to_string(sizeof(xtf_attitudeheader))+std::string(" Bytes"));
            m_simState=simState::simHaveFileHeader;
            ms_frameListMutex.lock();
            m_frameList.push(new attiFrame(p_attitudePacket));
            ms_frameListMutex.unlock();
            delete p_attitudePacket;
        }
        if(m_ifile.eof()){
            LOG(debug,"Finished reading xtf file "+m_ifilePath);
            if(m_ifile.is_open())
                m_ifile.close();
            sleep(0.5);
            m_simState=simState::simStop;
            m_cmdRun=STOP_SIMULATOR;
        }
    }
    return 1;
}

int simulator::fetchFrame(Frame * &p_frame){
    if(m_frameList.size()>=1){
        ms_frameListMutex.lock();
        p_frame=m_frameList.front();
        m_frameList.pop();
        ms_frameListMutex.unlock();
        return 1;
    }
    return 0;
}

int simulator::getSimState(){
    return m_simState;
}

void simulator::increaseSimulatorNum(){
    ms_simulatorNumMutex.lock();
    ms_simulatorNum+=1;
    ms_simulatorNumMutex.unlock();
}
void simulator::decreaseSimulatorNum(){
    ms_simulatorNumMutex.lock();
    if(ms_simulatorNum)
        ms_simulatorNum-=1;
    ms_simulatorNumMutex.unlock();
}

