#include <iostream>
#include<math.h>
#include<cmath>
#include <conio.h>
//#include "Chapter 7"
#include "BRNG.cxx"
#include "ARMRNGP1.cxx"

//#include "DiscreteUniformRNG.cpp"
//#include "RayleighRNG.cpp"

#define M_PI 3.14159265

//double pdf(double x) {
//	return sqrt(r ^ 2 - x ^ 2);
//}


bool isPointInCircle(double X, double Y, double x0, double y0, double R) {

	int step = 0;

	auto pdf = [x0, y0](double x, double y) {return pow(x+x0, 2) + pow(y + y0, 2); };

	return (pow(R, 2) <= pdf(X, Y));

}

double integral(int n) {
	int e = 0;
	double x;
	double y;
	for (int i = 0; i < n; i++) {
		do {
			x = -2 + 4 * brng();
			y = -2 + 4 * brng();
			e++;
		}
		while(!isPointInCircle(x, y, -1.17, 1.27, 0.57)||!isPointInCircle(x, y, -0.51, 0.51, 1.08) || !isPointInCircle(x, y, 0.88, -0.67, 1.01));
		
	}
	return (8)*(double)n/e;
}

int main() {

	//double r = 5.0;

	int n = 9*10;

	double aFunc = integral(n);

	printf("Calculated: %.4f\n", aFunc);

	_getch();

	return 0;
}