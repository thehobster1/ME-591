////////////////////////////////////////////////////////////////////////////////////////////////////
// Generator of a discrete integer random variable with uniform distribution from 0 to (N-1)
//--------------------------------------------------------------------------------------------------
// ME 408/5508 Non-equilibrium gas dynamics, Spring 2024
// Alexey N. Volkov, Univesity of Alabama, avolkov1@ua.edu
////////////////////////////////////////////////////////////////////////////////////////////////////

        int irand_uniform ( int N ) ////////////////////////////////////////////////////////////////
	{ 
                return int ( N * brng () );
	} //////////////////////////////////////////////////////////////////////////////////////////
