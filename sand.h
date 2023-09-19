class sand_particle
{
public:
    int coord_x, coord_y;
    sand_particle();
    sand_particle(int x, int y);
    bool fall(sand_particle* particles_array);
    bool draw(HANDLE cmd_handle, char symbol);
};