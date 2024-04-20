////////////////////////////////////////////////////////////////////////////////////////////////////
// Generator of 3D isotropic random vectors of unit length
//--------------------------------------------------------------------------------------------------
// ME 408/5508 Non-equilibrium gas dynamics, Spring 2024
// Alexey N. Volkov, Univesity of Alabama, avolkov1@ua.edu
////////////////////////////////////////////////////////////////////////////////////////////////////

        void v3rand_isotropic ( double *R ) ////////////////////////////////////////////////////////
        {
        double	cosT = 1.0 - 2.0 * brng ();
        double  sinT = sqrt ( 1.0 - cosT * cosT );
        double	E = 2.0 * M_PI * brng ();
	        R[0] = cosT;
	        R[1] = sinT * cos ( E );
	        R[2] = sinT * sin ( E );
        } 
