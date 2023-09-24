#include <iostream>
#include <Windows.h>
#include "particle_mesh.h"

COORD get_random_sp(int* particles_quant);

int main()
{
    COORD new_coords;
    new_coords.X = 0;
    new_coords.Y = 0;
    particle_mesh mesh(32, 32);
    int particles_quant = 0;
    while(true)
    {
        mesh.make_particle(get_random_sp(&particles_quant));
        /*for (int i = 0; i < 16; i++)
        {
            if (new_coords.X > 16)
                continue;
            mesh.make_particle(new_coords);
            new_coords.X++;
        }*/
        mesh.fall_particles();
        Sleep(1000);
    }
}

COORD get_random_sp(int* particles_quant)
{
    COORD new_coordinates;
    new_coordinates.X = -5;
    new_coordinates.Y = -5;
    if((*particles_quant) == 32)
        return new_coordinates;

    int x, y;
    y = 0;
    x = rand() % 32;
    new_coordinates.X = x;
    new_coordinates.Y = y;
    (*particles_quant)++;

    return new_coordinates;
}