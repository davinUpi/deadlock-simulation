#include "../includes/Program.h"

Program::Program(const std::vector<int>& addresses, int runTime)
    : resourceAddresses(addresses), state(Waiting),
      runningTime(runTime), waitingTime(0), totalTime(0) {}

void Program::loop(int time, std::vector<Resource>& resources) {
    totalTime += time;

    switch (state) {
        case Waiting:
            if (checkResourcesAcquired(resources)) {
                state = Running;
                waitingTime = 0;
            } else {
                waitingTime += time;
            }
            break;
        case Running:
            if (totalTime - waitingTime >= runningTime) {
                state = Done;
                releaseResources(resources);
            }
            break;
        case Done:
            // Do nothing, the program has finished executing
            break;
    }
}

bool Program::checkResourcesAcquired(std::vector<Resource>& resources) const {
    for (int address : resourceAddresses) {
        if (!resources[address].requestResource()) {
            return false;
        }
    }
    return true;
}

void Program::releaseResources(std::vector<Resource>& resources) const {
    for (int address : resourceAddresses) {
        resources[address].releaseResource();
    }
}

const std::vector<int>& Program::getResourceAddresses() const {
    return resourceAddresses;
}

ProgramState Program::getState() const {
    return state;
}

int Program::getRunningTime() const {
    return runningTime;
}

int Program::getWaitingTime() const {
    return waitingTime;
}

int Program::getTotalTime() const {
    return totalTime;
}
