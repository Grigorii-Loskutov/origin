#include "math_func.h"
double sum_my(double N1, double N2) {
	return N1 + N2;
}
double sub_my(double N1, double N2) {
	return N1 - N2;
}
double mult_my(double N1, double N2) {
	return N1 * N2;
}
double div_my(double N1, double N2) {
	return N1 / N2;
}
double pow_my(double N1, double N2) {
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