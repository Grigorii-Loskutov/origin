#include <string.h>
#include "Camel.h"
Camel::Camel() : Vehicle(true, "�������", 10, 30, 5, 8, 0) {}

double Camel::get_time(double range) {
	double time = 0;
	time = range / speed;
	double temp1 = time / run_time;
	double temp2 = static_cast<double>(static_cast<int>(temp1));
	unsigned rest_number = static_cast<int>(temp1);
	if (temp1 - temp2 == 0) {
		rest_number--;
	}
	else {
		nullptr;
	}
	if (rest_number == 1) {
		time = time + rest_time1;
	}
	else if (rest_number > 1) {
		time = time + rest_time1 + (rest_number - 1) * rest_time2;
	}
	return time;
}
