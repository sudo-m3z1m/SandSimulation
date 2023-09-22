#include "draw_manager.h"

void draw_manager::clear_screen()
{
    std::cout << "\033[2J\033[1;1H";
}

void draw_manager::draw_particles(sand_particle** particles_mash)
{
    clear_screen();
    HANDLE cmd_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    int size_x, size_y;
    size_x = sizeof(particles_mash) / sizeof(particles_mash[0]);
    size_y = sizeof(particles_mash) / sizeof(particles_mash[0][0]) / size_x;
    
    for(int x = 0; x < size_x; x++)
    {
        for(int y = 0; y < size_y; y++)
        {
            char symbol;
            DWORD entered_characters;
            COORD particle_coordinates;
            symbol = rand() % 2;
            particle_coordinates = particles_mash[x][y].coordinates;
            FillConsoleOutputCharacter(cmd_handle, symbol, 1, particle_coordinates, &entered_characters);
        }
    }
}