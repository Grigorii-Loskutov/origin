#include "math_func.h"
#include <math.h>
double math_func::sum(double N1, double N2) {
	return N1 + N2;
}
double math_func::sub(double N1, double N2) {
	return N1 - N2;
}
double math_func::mult(double N1, double N2) {
	return N1 * N2;
}
double math_func::div(double N1, double N2) {
	return N1 / N2;
}
double math_func::pow(double N1, double N2) {
	double result = N1;
	if (N2 != static_cast<double>(static_cast<int> (N2))) {
		result = 0;
	}
	else if (N2 == 0) {
		result = 1;
	}
	else
	{
		for (unsigned iter = 1; iter < N2; iter++) {
			result *= N1;
		}
		return result;
	}
}