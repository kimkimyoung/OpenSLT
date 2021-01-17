#ifndef FRAME_H_
#define FRAME_H_
#include <iostream>
#include <utility>
#include <time.h>
#include "logger.h"
#include "xtf.h"

float getTimeStamp(unsigned short year,
                    unsigned char month,
                    unsigned char day,
                    unsigned char hour,
                    unsigned char minute,
                    unsigned char second,
                    unsigned char hseconds);

class Frame{
public:
    Frame(){};
    ~Frame(){};
public:
    unsigned char packetType;
    float timeStamp;
};

class pingFrame: public Frame{
    public:
        pingFrame(xtf_pingpacket* p_pingPacket,xtf_fileheader fileHeader):
            pingNumber(p_pingPacket->pingHeader.PingNumber),
            soundVelocity(p_pingPacket->pingHeader.SoundVelocity),
            shipSpeed(p_pingPacket->pingHeader.ShipSpeed),
            shipGyro(p_pingPacket->pingHeader.ShipGyro),
            sensorSpeed(p_pingPacket->pingHeader.SensorSpeed),
            sensorYcoordinate(p_pingPacket->pingHeader.SensorYcoordinate),
            sensorXcoordinate(p_pingPacket->pingHeader.SensorXcoordinate),
            sensorPrimaryAltitude(p_pingPacket->pingHeader.SensorPrimaryAltitude),
            sensorPitch(p_pingPacket->pingHeader.SensorPitch),
            sensorRoll(p_pingPacket->pingHeader.SensorRoll),
            sensorHeading(p_pingPacket->pingHeader.SensorHeading),
            slantRange(p_pingPacket->pingChanHeader[0].SlantRange),
            bytesPerSample(fileHeader.chaninfo[0].BytesPerSample),
            numSamples(p_pingPacket->pingChanHeader[0].NumSamples){
                packetType=XTF_DATA_SIDESCAN;
                timeStamp=getTimeStamp(p_pingPacket->pingHeader.Year,
                                        p_pingPacket->pingHeader.Month,
                                        p_pingPacket->pingHeader.Day,
                                        p_pingPacket->pingHeader.Hour,
                                        p_pingPacket->pingHeader.Minute,
                                        p_pingPacket->pingHeader.Second,
                                        p_pingPacket->pingHeader.HSeconds);
                p_data[0]=p_pingPacket->p_ping[0];
                p_data[1]=p_pingPacket->p_ping[1];
        }
        ~pingFrame(){
            if(p_data[0])
                free(p_data[0]);
            if(p_data[1])
                free(p_data[1]);
            LOG(debug,"Have delete a ping packet");
        }
    public:
        unsigned int pingNumber;
        float soundVelocity;
        float shipSpeed;
        float shipGyro;
        float sensorSpeed;
        double sensorYcoordinate;
        double sensorXcoordinate;
        float sensorPrimaryAltitude;
        float sensorPitch;
        float sensorRoll;
        float sensorHeading;
        float slantRange;
        unsigned short bytesPerSample;
        unsigned int numSamples;
        void * p_data[2];
};

class bathmetryFrame: public Frame{
    public:
        bathmetryFrame(xtf_bathmetrypacket* p_bathmetryPacket,xtf_fileheader fileHeader):
            pingNumber(p_bathmetryPacket->bathmetryHeader.PingNumber),
            soundVelocity(p_bathmetryPacket->bathmetryHeader.SoundVelocity),
            shipSpeed(p_bathmetryPacket->bathmetryHeader.ShipSpeed),
            shipGyro(p_bathmetryPacket->bathmetryHeader.ShipGyro),
            sensorSpeed(p_bathmetryPacket->bathmetryHeader.SensorSpeed),
            sensorYcoordinate(p_bathmetryPacket->bathmetryHeader.SensorYcoordinate),
            sensorXcoordinate(p_bathmetryPacket->bathmetryHeader.SensorXcoordinate),
            sensorPrimaryAltitude(p_bathmetryPacket->bathmetryHeader.SensorPrimaryAltitude),
            sensorPitch(p_bathmetryPacket->bathmetryHeader.SensorPitch),
            sensorRoll(p_bathmetryPacket->bathmetryHeader.SensorRoll),
            sensorHeading(p_bathmetryPacket->bathmetryHeader.SensorHeading),
            yaw(p_bathmetryPacket->bathmetryHeader.Yaw),
            bytesPerSample(fileHeader.chaninfo[0].BytesPerSample){
            packetType=XTF_DATA_BATHYMETRY;
            numSamples=p_bathmetryPacket->bathmetryHeader.packetHeader.NumBytesThisRecord-sizeof(xtf_pingheader);
            timeStamp=getTimeStamp(p_bathmetryPacket->bathmetryHeader.Year,
                                    p_bathmetryPacket->bathmetryHeader.Month,
                                    p_bathmetryPacket->bathmetryHeader.Day,
                                    p_bathmetryPacket->bathmetryHeader.Hour,
                                    p_bathmetryPacket->bathmetryHeader.Minute,
                                    p_bathmetryPacket->bathmetryHeader.Second,
                                    p_bathmetryPacket->bathmetryHeader.HSeconds);
            p_data=p_bathmetryPacket->p_bathmetry;
        }
        ~bathmetryFrame(){
            if(p_data)
                free(p_data);
            LOG(debug,"Have delete a bathmetry packet");
        }

    public:
        unsigned int pingNumber;
        float soundVelocity;
        float shipSpeed;
        float shipGyro;
        float sensorSpeed;
        double sensorYcoordinate;
        double sensorXcoordinate;
        float sensorPrimaryAltitude;
        float sensorPitch;
        float sensorRoll;
        float sensorHeading;
        float yaw;
        unsigned short bytesPerSample;
        unsigned int numSamples;
        void * p_data;
};

class attiFrame: public Frame{
    public:
        attiFrame(xtf_attitudeheader* p_attiHeader):
        pitch(p_attiHeader->Pitch),
        roll(p_attiHeader->Roll),
        heave(p_attiHeader->Heave),
        yaw(p_attiHeader->Yaw),
        heading(p_attiHeader->Heading){
            packetType=XTF_DATA_ATTITUDE;
            timeStamp=p_attiHeader->TimeTag;
        }
        ~attiFrame(){
            LOG(debug,"Have deleted an attitude packet");
        }
    public:
        float pitch;
        float roll;
        float heave;
        float yaw;
        float heading;
};

#endif
