////////////////////////////////////////////////////////////////////////////////////////////////////
// Generator of a continuous random variable based on the acceptance and rejection method (ARM)
//--------------------------------------------------------------------------------------------------
// ME 408/508 Non-equilibrium gas dynamics, Spring 2024
// Alexey N. Volkov, Univesity of Alabama, avolkov1@ua.edu
////////////////////////////////////////////////////////////////////////////////////////////////////

        void frand_arm ( double a, double b, double c, double (*pdf) ( double x, double y ), int &n , double &X, double &Y) //////////////
        // Here pdf is the function calculating the PDF of the random variable
        { //////////////////////////////////////////////////////////////////////////////////////////
        //double	X, Y;
	        do {
		        X = a + ( b - a ) * brng ();
		        Y = c * brng ();
				n++;
	        } while ( 1 < pdf ( X,Y ) );
	        //return X;
        } //////////////////////////////////////////////////////////////////////////////////////////
