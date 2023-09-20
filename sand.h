#include <Windows.h>
#include <iostream>

class sand_particle
{
public:
    COORD coordinates;
    sand_particle();
    sand_particle(int x, int y);
    bool fall(sand_particle* particles_array);
    bool draw(HANDLE cmd_handle, char symbol);
};