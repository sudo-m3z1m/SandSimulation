#include "sand.h"

class particle_mash
{
private:
    int x, y;
    int* mash;

public:
    particle_mash();
    sand_particle place_particle(int part_x, int part_y);
    bool check_particles(sand_particle particle);
};
