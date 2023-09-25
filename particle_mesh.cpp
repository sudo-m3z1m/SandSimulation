#include "particle_mesh.h"

particle_mesh::particle_mesh(int width, int height)
{
    x = width;
    y = height;
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
    return new_particle;
}

COORD particle_mesh::check_particles(int part_x, int part_y)
{
    COORD new_coords;
    sand_particle empty_part;
    sand_particle part;
    int new_y, new_x_right, new_x_left;

    part_x = min(30, max(part_x, 1));
    part_y = min(30, max(part_y, 1));
    
    part = mesh[part_x][part_y];

    new_y = part_y + 1;
    new_x_right = part_x + 1;
    new_x_left = part_x - 1;

    new_x_left = min(30, max(new_x_left, 1));
    new_x_right = min(30, max(new_x_right, 1));

    new_coords.X = part_x;
    new_coords.Y = part_y;

    if (part.is_empty)
        return new_coords;

    if(mesh[part_x][new_y].is_empty)
    {
        mesh[part_x][new_y] = mesh[part_x][part_y];
        mesh[part_x][part_y] = empty_part;

        new_coords.X = part_x;
        new_coords.Y = new_y;
        return new_coords;
    }

    if(mesh[new_x_right][new_y].is_empty)
    {   
        mesh[new_x_right][part_y] = part;
        mesh[part_x][part_y] = empty_part;
        new_coords.X = new_x_right;
        new_coords.Y = part_y;
        return new_coords;
    }

    if (mesh[new_x_left][new_y].is_empty)
    {
        mesh[new_x_left][part_y] = mesh[part_x][part_y];
        mesh[part_x][part_y] = empty_part;

        new_coords.X = new_x_left;
        new_coords.Y = part_y;
        return new_coords;
    }

    else
        return new_coords;
}

void particle_mesh::fall_particles()
{
    for (int buff_x = 0; buff_x < x; buff_x++)
    {
        for (int buff_y = 0; buff_y < y; buff_y++)
        {
            mesh[buff_x][buff_y].pos_changed = false;
        }
    }

    for(int buff_x = 0; buff_x < x; buff_x++)
    {
        for(int buff_y = 0; buff_y < y; buff_y++)
        {
            COORD new_particle_coordinates;
            sand_particle* part;
            part = &mesh[buff_x][buff_y];
            //cout << buff_x << endl;
            if (part->pos_changed)
                continue;
            part->pos_changed = true;
            new_particle_coordinates = check_particles(buff_x, buff_y);
            //part->move(new_particle_coordinates);
        }
    }
    draw_manager::draw_particles(mesh);
}