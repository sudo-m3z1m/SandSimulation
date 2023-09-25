#include "draw_manager.h"

void draw_manager::clear_screen()
{
    std::cout << "\033[2J\033[1;1H";
}

void draw_manager::draw_particles(sand_particle** particles_mesh)
{
    //clear_screen();
    HANDLE cmd_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    int size_x, size_y;
    char symbols[2]{ '0', '1' };
    size_x = 32;
    size_y = 32;

    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            char symbol;
            DWORD entered_characters;
            COORD particle_coordinates;
            symbol = symbols[rand() % 2];
            particle_coordinates.X = i;
            particle_coordinates.Y = j;
            if (particles_mesh[i][j].is_empty)
            {
                FillConsoleOutputCharacter(cmd_handle, ' ', 1, particle_coordinates, &entered_characters);
                continue;
            }
            FillConsoleOutputCharacter(cmd_handle, symbol, 1, particle_coordinates, &entered_characters);
        }
    }
}