#include <Windows.h>
#include <iostream>

class sand_particle
{
public:
    COORD coordinates;
    sand_particle();
    bool fall(COORD new_coordinates);
};