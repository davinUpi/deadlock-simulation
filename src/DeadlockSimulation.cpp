#include "../includes/DeadlockSimulation.h"
#include <iostream>
#include <algorithm>
#include<windows.h> 

DeadlockSimulation::DeadlockSimulation(const std::vector<int>& maxPrograms) {
    for (int max : maxPrograms) {
        resources.emplace_back(max);
    }
}

void DeadlockSimulation::addProgram(const std::vector<int>& resourceAddresses, int runningTime) {
    programs.emplace_back(resourceAddresses, runningTime);
}

bool DeadlockSimulation::detectDeadlock() const {
    for (const auto& program : programs) {
        if (program.getState() == Waiting && program.getWaitingTime() >= 5) {
            return true;
        }
    }
    return false;
}

void DeadlockSimulation::simulateDeadlock() {
    int time = 0;
    bool deadlockDetected = false;

    while (!deadlockDetected && !std::all_of(programs.begin(), programs.end(), [](const Program& program) {
        return program.getState() == Done;
    })) {
        time++;
        for (auto& program : programs) {
            if (program.getState() != Done) {
                program.loop(1, resources); // Simulate 1 unit of time
            }
        }

        if (time % 5 == 0) {
            deadlockDetected = detectDeadlock();
        }
        std::cout<<time<<std::endl;
        Sleep(1000);
    }

    if (deadlockDetected) {
        std::cout << "Deadlock detected and simulation terminated after 5 seconds of deadlock." << std::endl;
    } else {
        std::cout << "All programs completed execution. Simulation terminated." << std::endl;
    }
}

void DeadlockSimulation::presetAcquiredResources(const std::vector<int>& resourceIndices, int programIndex) {
    if (programIndex >= 0 && programIndex < programs.size()) {
        Program& program = programs[programIndex];
        program.setAcquiredResources(resourceIndices);
    }
}

const std::vector<Resource>& DeadlockSimulation::getResources() const {
    return resources;
}

const std::vector<Program>& DeadlockSimulation::getPrograms() const {
    return programs;
}

