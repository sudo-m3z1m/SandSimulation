#include "sand.h"

class particle_mesh
{
private:
    int x, y;
    sand_particle** mesh;

public:
    particle_mesh(int x = 32, int y = 32);
    sand_particle make_particle(COORD coord);
    COORD check_particles(sand_particle particle);
};
