#include <string.h>
#include "FastCamel.h"
FastCamel::FastCamel() : Vehicle(true, "�������-���������", 40, 10, 5, 6.5, 8) {}

double FastCamel::get_time(double range) {
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
	else if (rest_number == 2) {
		time = time + rest_time1 + rest_time2;
	}
	else if (rest_number > 2) {
		time = time + rest_time1 + rest_time2 + (rest_number - 2) * rest_time3;
	}
	else { nullptr; }
	return time;
}
