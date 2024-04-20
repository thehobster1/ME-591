#include <iostream>
#include<math.h>
#include<cmath>
#include <conio.h>
//#include "Chapter 7"
#include "BRNG.cxx"
#include "ARMRNGP1.cxx"
#include "DiscreteStdRNG.cxx"
#include "frand_discrete_standard.cpp"

//#include "DiscreteUniformRNG.cpp"
//#include "RayleighRNG.cpp"

#define M_PI 3.14159265

//double pdf(double x) {
//	return sqrt(r ^ 2 - x ^ 2);
//}


int main() {

	//double r = 5.0;

	int n = 10000;

	double E;
	double sigma;

	double X[] = { -3, -10, 3.5, 5, 7.25 };
	double P[] = { 0.15, 0.05, 0.4, 0.2, 0.2 };

	double calcSigma = 0.0;

	double calcE = 0.0;
	for (int i = 0; i < *(&X + 1) -X; i++) {
		calcE += P[i] * X[i];

	}
	for (int i = 0; i < *(&X + 1) - X; i++) {
		calcSigma += P[i] * pow(X[i] - calcE,2);

	}

	calcSigma = sqrt(calcSigma);
	
	
	disStdMean(n, X, P, E, sigma);

	//calcSigma = sqrt(n) * abs(E - calcE);

	printf("Calculated Mean: %.4f\tCalculated Standard Deviation: %.4f\nEstimated Mean: %.4f\tEstimated Standard Deviation: %.4f\n", calcE, calcSigma, E, sigma);

	_getch();

	return 0;
}