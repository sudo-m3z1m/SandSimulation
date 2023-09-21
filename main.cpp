#include <iostream>
#include <Windows.h>
#include "sand.h"

sand_particle particles[64];

 int make_particle(int particle_quant, sand_particle* particles_array)
 {
	 int particles_max_quantity = 40;
	 int max_coord_x = 10;
	 int random_coord_x;

	 if(particle_quant >= 40)
		 return particle_quant;

	 random_coord_x = rand() % max_coord_x;
	 sand_particle new_particle(random_coord_x, 0);
	 particle_quant++;
 }

 bool fall(sand_particle* part)
 {
	 if ((*part).coordinates.Y >= 20)
	 {
		 return false;
	 }

	 for (int i = 0; i < 64; i++)
	 {
		 sand_particle particle = particles[i];

		 if ((*part).coordinates.X == particle.coordinates.X)
		 {
			 if (((*part).coordinates.Y + 1) == (particle.coordinates.Y))
			 {
				 return false;

			 }
		 }
	 }
	 part->coordinates.Y += 1;
	 return true;
 }

int main()
{
	int part_quant = 0;
	while (true)
	 {
		 int new_x_coord;
		 new_x_coord = rand() % 16;
		 sand_particle new_part(new_x_coord, 0);
		 particles[part_quant] = new_part;
		 part_quant++;

		 HANDLE cmd_handle = GetStdHandle(STD_OUTPUT_HANDLE);

		 for (int i = 0; i < 64; i++)
		 {
			 sand_particle* part = &particles[i];
			 part->draw(cmd_handle, ' ');
			 fall(part);
			 part->draw(cmd_handle, 'A');
		 }
		 Sleep(100);
	 }
}