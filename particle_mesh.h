#include "draw_manager.h"

class particle_mesh
{
private:
    int x, y;
    sand_particle** mesh;

public:
    void draw_particles();
    particle_mesh(int width = 32, int height = 32);
    sand_particle make_particle(COORD coord);
    COORD check_particles(int part_x, int part_y);
    void fall_particles();
};
