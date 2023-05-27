#pragma once

#include <vector>
#include "Resource.h"
#include "Program.h"

/**
 * @brief A class to simulate deadlock
 * 
 * The class is made specifically to simulate deadlock
 * currently only have classic looping where setting
 * the preset acquired resources to the programs may
 * cause a deadlock. If no preset, it will not have a 
 * deadlock
 * 
 * @author davin w/ co-pilot chatGPT
 * 
 */
class DeadlockSimulation {
private:
    std::vector<Resource> resources;
    std::vector<Program> programs;

public:
/**
 * @brief Construct a new Deadlock Simulation object
 * 
 * set up the resources that is in the simulation
 * 
 * @todo makes it so that you can also set programs in the constructor
 * 
 * @param maxPrograms 
 */
    DeadlockSimulation(const std::vector<int>& maxPrograms);

/**
 * @brief add a program into the simulation
 * 
 * add a program into the simulation by entering the required
 * parameters to initialize a Program object
 * 
 * @param resourceAddresses 
 * @param runningTime 
 */
    void addProgram(const std::vector<int>& resourceAddresses, int runningTime);

/**
 * @brief A function to check if deadlock happens
 * 
 * The method checks for deadlock by checking if all programs
 * are stuck in waiting state for an extended period of time
 * 
 * @todo make the deadlock check time configurable and set as protected
 * 
 * @return true 
 * @return false 
 */
    bool detectDeadlock() const;

/**
 * @brief method to simulate the process loop.
 * 
 * This method will simulate the process loop
 * using the pre-configured settings. Make sure to
 * already set everything (resources, programs) before
 * using this method.
 * 
 * The loop will end if all the programs are done executing or
 * deadlock happens
 * 
 */
    void simulateDeadlock();

/**
 * @brief To preset programs already have acquired certain resources
 * 
 * This method allows presetting acquired resources by a certain
 * programs. Make sure to only set resources it actually needs
 * 
 * @todo exception if the preseted resource is not required by the program
 * 
 * @param resourceIndices 
 * @param programIndex 
 */
    void presetAcquiredResources(const std::vector<int>& resourceIndices, int programIndex);

/**
 * @brief Get the Resources object
 * 
 * @return const std::vector<Resource>& 
 */
    const std::vector<Resource>& getResources() const;

/**
 * @brief Get the Programs object
 * 
 * @return const std::vector<Program>& 
 */
    const std::vector<Program>& getPrograms() const;
};
