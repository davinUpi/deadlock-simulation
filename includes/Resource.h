#pragma once

class Resource {
private:
    int maxPrograms;
    int usedPrograms;

public:
    Resource(int maxPrograms);

    bool requestResource();

    void releaseResource();

    int getMaxPrograms() const;

    int getUsedPrograms() const;
};
