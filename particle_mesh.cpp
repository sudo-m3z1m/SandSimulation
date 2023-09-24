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
    sand_particle new_particle(false);
    new_particle.coordinates = coord;
    mesh[coord.X][coord.Y] = new_particle;
}

COORD particle_mesh::check_particles(sand_particle particle)
{
    COORD new_coords;
    int new_y, new_x_right, new_x_left;
    new_y = particle.coordinates.Y + 1;
    new_x_right = particle.coordinates.X + 1;
    new_x_left = particle.coordinates.X - 1;

    if(mesh[particle.coordinates.X][new_y].is_empty)
    {
        new_coords.X = particle.coordinates.X;
        new_coords.Y = new_y;
        return new_coords;
    }

    if(mesh[new_x_left][new_y].is_empty)
    {
        if(mesh[new_x_left][new_y].is_empty)
        {
            new_coords.X = particle.coordinates.X + 1;
            new_coords.Y = new_y;
            return new_coords;
        }
        
        new_coords.X = particle.coordinates.X - 1;
        new_coords.Y = new_y;
        return new_coords;
    }
}

void particle_mesh::fall_particles()
{
    for(int buff_x = 0; buff_x < x; buff_x++)
    {
        for(int buff_y = 0; buff_y < y; buff_y++)
        {
            COORD new_particle_coordinates;
            sand_particle part;
            part = mesh[buff_x][buff_y];
            new_particle_coordinates = check_particles(part);
            part.move(new_particle_coordinates);
            draw_manager::draw_particles(mesh);
        }
    }
}