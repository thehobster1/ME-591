////////////////////////////////////////////////////////////////////////////////////////////////////
// Generator of a continuous random variable based on the acceptance and rejection method (ARM)
//--------------------------------------------------------------------------------------------------
// ME 408/508 Non-equilibrium gas dynamics, Spring 2024
// Alexey N. Volkov, Univesity of Alabama, avolkov1@ua.edu
////////////////////////////////////////////////////////////////////////////////////////////////////

        double frand_arm ( double a, double b, double c, double (*pdf) ( double X ) ) //////////////
        // Here pdf is the function calculating the PDF of the random variable
        { //////////////////////////////////////////////////////////////////////////////////////////
        double	X, Y;
	        do {
		        X = a + ( b - a ) * brng ();
		        Y = c * brng ();
	        } while ( Y > pdf ( X ) );
	        return X;
        } //////////////////////////////////////////////////////////////////////////////////////////
