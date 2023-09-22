#include <Windows.h>
#include "sand.h"

class draw_manager
{
public:
    draw_manager();
    static void draw_particles(sand_particle* particles_mash);
    static void clear_screen();
};