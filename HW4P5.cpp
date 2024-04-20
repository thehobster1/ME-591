#include <iostream>
#include<math.h>
#include<cmath>
#include <conio.h>
//#include "Chapter 7"
#include "BRNG.cxx"
#include "ARMRNGP1.cxx"
#include "DiscreteStdRNG.cxx"
#include "frand_discrete_standard.cpp"
#include "PoissonRNG.cxx"
#include "frand_X3.cpp"

//#include "DiscreteUniformRNG.cpp"
//#include "RayleighRNG.cpp"

#define M_PI 3.14159265

//double pdf(double x) {
//	return sqrt(r ^ 2 - x ^ 2);
//}


int main() {

	double a = 1;

	double b = 4;
	
	double n = 100;

	auto pdfE = [a, b](double x) {return 4.0/5.0*pow(x,5)/(pow(b,4)-pow(a,4)); };

	double mu = pdfE(b) - pdfE(a);

	auto pdfV = [a,b, mu](double x) {return 4.0/(pow(b,4)-pow(a,4))*(pow(x,6)/6-2*mu*pow(x,5)/5+mu*mu*pow(x,4)/4); };

	double sigma = sqrt(pdfV(b) - pdfV(a));

	//double x;
	double temp;
	
	double E = 0.0;
	double V = 0.0;

	for (int i = 0; i < n; i++) {
		temp = frand_X3(a, b);
		E += temp;
		V += temp * temp;
	}
	E = E / n;
	V = sqrt(V / n - E * E);

	//calcSigma = sqrt(n) * abs(E - calcE);

	printf("Calculated\nMean: %.4f\tVarience: %.4f\n\n\nMonte Carlo\nMean: %.4f\tVarience: %.4f\n", mu, sigma, E, V);

	_getch();

	return 0;
}