void disStdMean(int n, double* X, double* P, double& mean, double& dev) {
	double E = 0.0;
	double V = 0.0;
	double temp;
	double Pcum[5];
	Pcum[0] = P[0];
	for (int i = 1; i < 5; i++) {
		Pcum[i] = Pcum[i - 1] + P[i];
	}
	for (int i = 0; i < n; i++) {
		temp = frand_discrete_std(X, Pcum);
		E += temp;
		V += temp*temp;
	}
	mean = E / n;
	dev = sqrt(V / n - mean * mean);

}

