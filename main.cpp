#include <iostream>
#include <Windows.h>

bool sand_fall(HANDLE cmd_handle, int start_pos_x)
{
    COORD self_coordinates;
    self_coordinates.X = start_pos_x;

    for(int y = 0; y < 20; y++)
    {
        DWORD characters;
        FillConsoleOutputCharacter(cmd_handle, ' ', 1, self_coordinates, &characters);
        self_coordinates.Y = y;
        FillConsoleOutputCharacter(cmd_handle, 'A', 1, self_coordinates, &characters);
        Sleep(1);
    }
    return true;
}

int main()
{
    HANDLE cmd_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordinates;
    int particle_spawn_range = 100;
    int border = 20;
    int particles_quantity = 60;

    for (int particle = 0; particle < particles_quantity; particle++)
    {
        int particle_draw_x = rand() % particle_spawn_range;
        sand_fall(cmd_handle, particle_draw_x);
    }
}