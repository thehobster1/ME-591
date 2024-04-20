////////////////////////////////////////////////////////////////////////////////////////////////////
// Generator of discrete random vector with Maxwell-Boltzmann distribution
//--------------------------------------------------------------------------------------------------
// ME 408/508 Non-equilibrium gas dynamics, Spring 2024
// Alexey N. Volkov, Univesity of Alabama, avolkov1@ua.edu
////////////////////////////////////////////////////////////////////////////////////////////////////

void vrand_MB ( double *v, double m, double *u, double T) /////////////////////////////////
{ 
    double  BOLTZMANN_CONSTANT = 1.380662E-23; // (J/K)
    double  sRT = sqrt ( BOLTZMANN_CONSTANT * T / m );
    v[0] = frand_Gaussian ( u[0], sRT );
    v[1] = frand_Gaussian ( u[1], sRT ); 
    v[2] = frand_Gaussian ( u[2], sRT ); 

    
}
