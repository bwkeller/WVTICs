#include "../globals.h"

#define DENSITY_STEP 0.5

float TopHat_Density ( const int ipart )
{
    float x = P[ipart].Pos[0] / Problem.Boxsize[0];

    const double rho0 = 1.0;
    const double halfstep = DENSITY_STEP * rho0;

    const double rho_max = rho0 + halfstep;
    const double rho_min = rho0 - halfstep;

    if ( x <= 0.1 || x > 0.9 ) {
        return rho_min;
    } else if ( x > 0.4 && x <= 0.6 ) {
        return rho_max;
    } else if ( x > 0.6 ) {
        return rho_max - ( rho_max - rho_min ) * ( x - 0.6 ) / 0.3;
    }

    return rho_min + ( rho_max - rho_min ) * ( x - 0.1 ) / 0.3;
}
