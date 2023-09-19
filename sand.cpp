#include <sand.h>
#include <Windows.h>

sand_particle::sand_particle()
{
}

sand_particle::sand_particle(int x, int y)
{
    coord_x = x;
    coord_y = y;
}

bool sand_particle::fall(sand_particle* particles_array)
{
    for(int i = 0; i < 255; i++)
    {
        if((coord_x == particles_array[i].coord_x) && (coord_y == (particles_array[i].coord_y - 1)))
        {
            break;
        }
        if(coord_y == 40)
        {
            break;
        }
        else
            coord_y++;
    }
}

bool sand_particle::draw(HANDLE cmd_handle, char symbol)
{
    DWORD drawed_characters;
    COORD coordinates;

    coordinates.X = coord_x;
    coordinates.Y = coord_y;
    FillConsoleOutputCharacter(cmd_handle, symbol, 1, coordinates, &drawed_characters);
}