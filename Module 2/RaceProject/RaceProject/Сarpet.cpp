#include <string.h>
#include "Carpet.h"
Carpet::Carpet() : Vehicle(false, "����-������", 10, 0, 0, 0, 0) {}

double Carpet::get_time(double range) {
	double time = 0;
	time = range / speed;
	if (range < 1000) {
		nullptr;
	}
	else if (range < 5000 and range >1000) {
		time = time * 0.97;
	}
	else if (range > 5000 and range < 10000) {
		time = time * 0.9;
	}
	else {
		time = time * 0.95;
	}
	return time;
}
