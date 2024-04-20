////////////////////////////////////////////////////////////////////////////////////////////////////
// Generator of a discrete integer random variable with Poisson distribution
//--------------------------------------------------------------------------------------------------
// ME 408/508 Non-equilibrium gas dynamics, Spring 2024
// Alexey N. Volkov, Univesity of Alabama, avolkov1@ua.edu
////////////////////////////////////////////////////////////////////////////////////////////////////

int irand_Poisson ( double E ) /////////////////////////////////////////////////////////////
// Here E is the mean and variance of the Poisson distribution
{ //////////////////////////////////////////////////////////////////////////////////////////
	double 	expE = exp ( - E ); 
	double 	prod = 1.0;
	int   	i = 0;
	do {
		i++;
		prod *= brng ();
	} while ( prod >= expE );
	return i - 1;
} 
