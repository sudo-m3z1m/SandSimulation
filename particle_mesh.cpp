#include "particle_mesh.h"

particle_mesh::particle_mesh(int x = 32, int y = 32)
{
    mesh = new sand_particle*[x];
    for(int i = 0; i < x; i++)
    {
        mesh[i] = new sand_particle[y];
    }
}

sand_particle particle_mesh::make_particle(COORD coord)
{
    sand_particle new_particle;
    new_particle.coordinates = coord;
    mesh[coord.X][coord.Y] = new_particle;
}

COORD particle_mesh::check_particles(sand_particle particle)
{
    // COORD coords_down, coords_down_left, coords_down_right;
    // coords_down.X = particle.coordinates.X;
    // coords_down.Y = particle.coordinates.Y + 1;

    // coords_down_left.X = particle.coordinates.X - 1;
    // coords_down_left.Y = particle.coordinates.Y + 1; //Useless theme
    
    // coords_down_right.X = particle.coordinates.X + 1;
    // coords_down_right.Y = particle.coordinates.Y + 1;

    // if()
    // {

    // }
}