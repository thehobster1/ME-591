#include <iostream>
#include<math.h>
#include<cmath>
#include <conio.h>
//#include "Chapter 7"
#include "BRNG.cxx"
#include "ARMRNG.cxx"

//#include "DiscreteUniformRNG.cpp"
//#include "RayleighRNG.cpp"

#define M_PI 3.14159265

//double pdf(double x) {
//	return sqrt(r ^ 2 - x ^ 2);
//}

int PointInCircle(double& X, double& Y, double x0, double y0, double R) {

	double (*pdfR)(double r) = [R](double r) { return r*r/(R*R); };
	
	double (*pdfT)(double theta) = [](double theta) { return theta / (2*M_PI); };

	double rRand = frand_arm(0, R, 1, pdfR);

	double thetaRand = frand_arm(0, 2*M_PI, 2*M_PI, pdfT);

		X = x0 + rRand * R * cos(thetaRand);
		Y = y0 + rRand * R * sin(thetaRand);
	
}

double integral(double n, double r) {
	double e = 0.0;
	double x;
	double y;
	for (int i = 0; i < n; i++) {
		PointInCircle(x, y, 0, 0, r);
		e += y;
	}
	return 2 * e / n;
}

int main() {

	integral(100000, r);
	return 0;
}
