#include "../globals.h"

#define DENSITY_STEP 0.5

float Sawtooth_Density(const int ipart)
{
    float x = P[ipart].Pos[0] / Problem.Boxsize[0];
    if (x > 0.5) {
        x -= 0.5;
    }

    double volume = Problem.Boxsize[0]*Problem.Boxsize[1]*Problem.Boxsize[2];
    double mass = Param.Npart * Problem.Mpart;

    const double rho0 = mass/volume;
    const double halfstep = DENSITY_STEP * rho0;

    const double rho_max = rho0 + halfstep;
    const double rho_min = rho0 - halfstep;

    return rho_min + (rho_max - rho_min) * x / 0.5;
}
