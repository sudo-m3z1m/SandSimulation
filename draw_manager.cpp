#include "draw_manager.h"

void draw_manager::clear_screen()
{
    std::cout << "\033[2J\033[1;1H";
}

void draw_manager::draw_particles(sand_particle* particles_mash)
{

}