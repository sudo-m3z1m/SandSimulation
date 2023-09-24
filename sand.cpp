#include "sand.h"

sand_particle::sand_particle(bool empty = true)
{
    is_empty = empty;
}

void sand_particle::move(COORD new_coordinates)
{
    coordinates = new_coordinates;
}