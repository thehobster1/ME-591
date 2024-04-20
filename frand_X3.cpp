double frand_X3(double a, double b) {
	double x = a + (b - a)*brng();
	auto pdf = [a,b](double x) {return 4 * pow(x, 3) / (pow(b, 4) - pow(a, 4)); };
	double	X, Y;
	do {
		X = a + (b - a) * brng();

		if (abs(a) > abs(b)) {
			Y = 4*pow(a,3)/(pow(b,4)-pow(a,4))* brng();
		}
		else {
			Y = 4*pow(b, 3) / (pow(b, 4) - pow(a, 4)) * brng();
		}
		
	} while (Y > pdf(X));
	return X;
	
	
}