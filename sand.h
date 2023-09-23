#include <Windows.h>
#include <iostream>

class sand_particle
{
public:
    COORD coordinates;
    bool is_empty;
    sand_particle(bool empty = false);
    bool fall(COORD new_coordinates);
};