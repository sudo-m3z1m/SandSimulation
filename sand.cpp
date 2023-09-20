#include "sand.h"

sand_particle::sand_particle()
{
}

sand_particle::sand_particle(int x, int y)
{
    coordinates.X = x;
    coordinates.Y = y;
}

bool sand_particle::fall(sand_particle* particles_array)
{
    for (int i = 0; i < 12; i++)
    {
        std::cout << coordinates.Y << std::endl;
        if ((coordinates.X == particles_array[i].coordinates.X) && (coordinates.X == (particles_array[i].coordinates.X - 1)))
        {
            break;
        }
        if (coordinates.Y >= 40)
        {
            break;
        }
        else
            coordinates.Y++;
            return true;
    }
        return false;
}

bool sand_particle::draw(HANDLE cmd_handle, char symbol)
{
    DWORD drawed_characters;

    FillConsoleOutputCharacter(cmd_handle, symbol, 1, coordinates, &drawed_characters);
    return true;
}