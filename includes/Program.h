#pragma once

#include <vector>
#include "Resource.h"

enum ProgramState { Waiting, Running, Done };

class Program {
private:
    std::vector<int> resourceAddresses;
    ProgramState state;
    int runningTime;
    int waitingTime;
    int totalTime;
    std::vector<int> acquiredResources;

public:
    Program(const std::vector<int>& addresses, int runTime);

    void loop(int time, std::vector<Resource>& resources);

    bool checkResourcesAcquired(std::vector<Resource>& resources) const;

    void releaseResources(std::vector<Resource>& resources) const;

    const std::vector<int>& getResourceAddresses() const;

    const std::vector<int>& getAcquiredResources() const {
        return acquiredResources;
    }

    void setAcquiredResources(const std::vector<int>& resources) {
        acquiredResources = resources;
    }

    ProgramState getState() const;

    int getRunningTime() const;

    int getWaitingTime() const;

    int getTotalTime() const;
};
