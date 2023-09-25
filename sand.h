#include <Windows.h>
#include <iostream>

class sand_particle
{
public:
    COORD coordinates;
    bool pos_changed = false;
    bool is_empty;
    sand_particle(bool empty = true);
    void move(COORD new_coordinates);
};