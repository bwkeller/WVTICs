/* profiles */

double Gas_Density_Profile ( const double, const double, const double );
void Read_param_file ( char * );
void Setup();
void Make_Positions();
void Make_IDs();
void Make_Magnetic_Fields();
void Make_Velocities();
void Make_Temperatures();
void Find_sph_quantities();
void Wvt_relax();
void Write_output ( bool );
void Regularise_sph_particles();
#ifdef EAT_PNG
void Setup_Density_From_Image();
#endif

/* Helper Monkeys */

void *Malloc_info ( const char *func, const char *file, const int line,
                    size_t size );
void *Realloc_info ( const char *func, const char *file, const int line,
                     void *ptr, size_t size );
void Free_info ( const char *func, const char *file, const int line, void *ptr );
void Assert_Info ( const char *func, const char *file, int line, int64_t expr,
                   const char *errmsg, ... );

double U2T ( double U );
double T2U ( double T );
double Density ( float rho );

void Print_Int_Bits128 ( const peanoKey val );
void Print_Int_Bits128r ( const peanoKey val );

/* From system libs */
double erand48 ( unsigned short * );

/* Problem Functions */
#include "problems/problems.h"
