#include "includes/DeadlockSimulation.h"
#include <iostream>

int main() {
    // Deadlock scenario with pre-acquired resources
    std::cout << "Deadlock Scenario with Pre-acquired Resources" << std::endl;
    std::vector<int> maxPrograms1{2, 2}; // Maximum program capacities for Resource A and Resource B

    DeadlockSimulation simulation1(maxPrograms1);

    simulation1.addProgram(std::vector<int>{0, 1}, 10);                // Program 1 requiring Resource A
    simulation1.addProgram(std::vector<int>{0,1,2}, 10);                // Program 2 requiring Resource B
    simulation1.addProgram(std::vector<int>{1,2}, 10);             // Program 3 requiring Resource A and Resource B

    // Pre-acquire resources for programs
    simulation1.presetAcquiredResources(std::vector<int>{1}, 0);           // Program 1 acquires Resource A
    simulation1.presetAcquiredResources(std::vector<int>{0,1}, 1);           // Program 2 acquires Resource B
    simulation1.presetAcquiredResources(std::vector<int>{2}, 2);        // Program 3 acquires Resource A and Resource B

    simulation1.simulateDeadlock();

    std::cout << std::endl;

    // No deadlock scenario with pre-acquired resources
    std::cout << "No Deadlock Scenario with Pre-acquired Resources" << std::endl;
    std::vector<int> maxPrograms2{2, 2}; // Maximum program capacities for Resource A and Resource B

    DeadlockSimulation simulation2(maxPrograms2);

    simulation2.addProgram(std::vector<int>{0, 1}, 10);               // Program 1 requiring Resource A and Resource B
    simulation2.addProgram(std::vector<int>{0, 1}, 10);               // Program 2 requiring Resource A and Resource B

    // Pre-acquire resources for programs
    simulation2.presetAcquiredResources(std::vector<int>{0, 1}, 0);         // Program 1 acquires Resource A and Resource B

    simulation2.simulateDeadlock();

    return 0;
}
