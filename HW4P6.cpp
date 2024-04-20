#include <iostream>
#include <math.h>
#include <cmath>
#include <conio.h>
//#include "Chapter 7"

#define M_PI 3.14159265

#include "BRNG.cxx"
#include "ARMRNGP1.cxx"
#include "DiscreteStdRNG.cxx"
#include "frand_discrete_standard.cpp"
#include "PoissonRNG.cxx"
#include "frand_X3.cpp"
#include "GaussianRNG.cxx"
#include "MaxwellBoltzmannRNG.cxx"


//#include "DiscreteUniformRNG.cpp"
//#include "RayleighRNG.cpp"



//double pdf(double x) {
//	return sqrt(r ^ 2 - x ^ 2);
//}


int main() {

	double u[3] = { 300, 200, -11 };
	double T = 100;
	double m = 28*1.66054*pow(10,-27);
	double v[3];

	double  kb = 1.380662E-23;

	double c = 2 * kb * T / m;

	int n = 10000;

	double U = 0.0;
	double temp = 0.0;
	double velocityAdd = 0.0;
	auto f = [c, n](double v, double u) {return (double) n / pow(c * M_PI, 1.5) * exp(-1.0 * pow(v - u, 2) / c);  };

	for (int i = 0; i < n; i++) {
		vrand_MB(v, m, u, T);

		velocityAdd += sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);

		//printf("%.4f\n", f(v[0], u[0]));

		U += v[0] * v[1] * v[2] * f(v[0], u[0]) * f(v[1], u[1]) * f(v[2], u[2]);
		temp += pow(v[0]-u[0],2)* pow(v[1] - u[1], 2)* pow(v[2] - u[2], 2)* f(v[0], u[0]) * f(v[1], u[1]) * f(v[2], u[2]);

	}
	U /= (double)n;
	temp *= m / (3 * (double)n * kb);
	
	double uMag = sqrt(u[0] * u[0] + u[1] * u[1] + u[2] * u[2]);
	

	printf("Calculated\nVelocity: %.4f\tTemp: %.4f\n\n\nMonte Carlo\nVelocity: %.4f\tTemp: %.4f\nVelocity Test: %.4f", uMag, T, U, temp, velocityAdd);


	_getch();

	return 0;
}