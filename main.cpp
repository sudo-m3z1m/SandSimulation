#include <iostream>
#include <Windows.h>
#include <sand.h>

bool update(sand_particle* particles_array)
{
    HANDLE cmd_handle;
    
    for(int i = 0; i < 255; i++)
    {
        particles_array[i].draw(cmd_handle, ' ');
        particles_array[i].fall(particles_array);
        particles_array[i].draw(cmd_handle, 'P');
    }
    Sleep(100);
    update(particles_array);
}

// int make_particle(int particle_quant, sand_particle* particles_array)
// {
//     int particles_max_quantity = 40;
//     int max_coord_x = 10;
//     int random_coord_x;

//     if(particle_quant >= 40)
//         return particle_quant;
    
//     random_coord_x = rand() % max_coord_x;
//     sand_particle new_particle(random_coord_x, 0);
//     particle_quant++;
// }

// bool sand_fall(HANDLE cmd_handle, int start_pos_x)
// {
//     COORD self_coordinates;
//     self_coordinates.X = start_pos_x;

//     for(int y = 0; y < 20; y++)
//     {
//         DWORD characters;
//         FillConsoleOutputCharacter(cmd_handle, ' ', 1, self_coordinates, &characters);
//         self_coordinates.Y = y;
//         FillConsoleOutputCharacter(cmd_handle, 'A', 1, self_coordinates, &characters);
//         Sleep(1);
//     }
//     return true;
// }

int main()
{
    sand_particle particles[256];
    
    for(int x = 0; x < 10; x++)
    {
        sand_particle new_particle(x, 0);
        particles[x] = new_particle;
    }
    update(particles);
}