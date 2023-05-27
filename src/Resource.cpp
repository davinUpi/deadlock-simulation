#include "../includes/Resource.h"

Resource::Resource(int maxPrograms) : maxPrograms(maxPrograms), usedPrograms(0) {}

bool Resource::requestResource() {
    if (usedPrograms < maxPrograms) {
        usedPrograms++;
        return true;
    }
    return false;
}

void Resource::releaseResource() {
    if (usedPrograms > 0) {
        usedPrograms--;
    }
}

int Resource::getMaxPrograms() const {
    return maxPrograms;
}

int Resource::getUsedPrograms() const {
    return usedPrograms;
}
