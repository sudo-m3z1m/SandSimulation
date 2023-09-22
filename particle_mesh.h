#include "sand.h"

class particle_mesh
{
private:
    int x, y;
    int* mesh;

public:
    particle_mesh();
    sand_particle place_particle(int part_x, int part_y);
    COORD check_particles(sand_particle particle);
};
