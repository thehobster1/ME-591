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

int PointInCircle(double& X, double& Y, double x0, double y0, double R) {

	int step = 0;

	//auto pdfR = [](double r) { return sqrt(-2*log(r)); };

	//auto pdfT = [](double theta) { return theta*(2 * M_PI); };

	//double rRand = frand_arm(0, 1, 1, pdfR, n)*R;

	//double thetaRand = frand_arm(0, 2 * M_PI, 2 * M_PI, pdfT, n);

	//X = x0 + rRand * cos(thetaRand);
	//Y = y0 + rRand * sin(thetaRand);

	auto pdf = [](double x, double y) {return x * x + y * y; };

	frand_arm(0, 1, 1, pdf, step, X, Y);
	X = R * X + x0;
	Y = R * Y + y0;
	return step;

}

double integral(int& n, double r) {
	int e = 0;
	double x;
	double y;
	double area = 0;
	double tru = M_PI*r*r;
	while (abs(tru - area)/tru > 0.01) {
		n += PointInCircle(x, y, 0, 0, r);
		e++;
		area = (2*r)*(2*r)*(double)e/n;
	}
	return area;
}

int main() {

	double r = 5.0;

	int n = 0;

	double aFunc = integral(n, r);

	double pi = aFunc/r/r;

	printf("Real: %.4f\tCalculated: %.4f\tRequired Points: %d\n", M_PI, pi, n);

	_getch();

	return 0;
}