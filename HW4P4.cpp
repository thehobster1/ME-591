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

//#include "DiscreteUniformRNG.cpp"
//#include "RayleighRNG.cpp"

#define M_PI 3.14159265

//double pdf(double x) {
//	return sqrt(r ^ 2 - x ^ 2);
//}


int main() {

	double E = 5;

	int poisson = irand_Poisson(E);
	

	//calcSigma = sqrt(n) * abs(E - calcE);

	printf("Poisson: %d\n", poisson);

	_getch();

	return 0;
}