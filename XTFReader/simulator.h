#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <string>
#include <string.h>
#include <unistd.h>
#include <queue>
#include <iostream>
#include <mutex>
#include <fstream>
#include <vector>
#include <thread>
#include <functional>
#include <cmath>

#include "xtf.h"
#include "frame.h"

#define START_SIMULATOR true
#define STOP_SIMULATOR false
#define MAX_NUM_SIMULATOR 4
#define INIT_SPEED 40000
#define MAX_SPEED 2500
#define MIN_SPEED 200000

enum simState{simCreated,simFailInit,simInit,simHaveFileHeader,simHavePing,
    simHaveAttitude,simHaveBathmetry,simStop};

class simulator{
public:
    simulator(std::string ifilePath);
    ~simulator();
    int initializeSimulator();
    int startSimulator();
    int stopSimulator();
    int pauseSimulator();
    int unpauseSimulator();
    int fetchFrame(Frame * &p_frame);
    int getSimState();
    int speedUp();
    int speedDown();
    int setSpeed(int speed);
    int getSpeed();
private:
    int runningSimulator();
    static void increaseSimulatorNum();
    static void decreaseSimulatorNum();

public:
    int _MAX_SPEED = MAX_SPEED;
    int _MIN_SPEED = MIN_SPEED;
    static int ms_simulatorNum;//number of created simulator
    static std::mutex ms_simulatorNumMutex;
    static std::mutex ms_frameListMutex;
    static std::vector<std::thread *> ms_threads;
    struct xtf_fileheader m_xtfFileHeader;

private:
    useconds_t dt;
    simState m_simState;//simulator runing state
    unsigned int m_packetNum;//number of packets have read
    bool m_cmdRun;//0:stop;1:run
    bool m_pause;

    std::fstream m_ifile;//simulator read data from ifile
    std::string m_ifilePath;
    std::queue<Frame *> m_frameList;
    std::condition_variable m_condPause;
    std::mutex m_pauseMutex;
};

#endif
