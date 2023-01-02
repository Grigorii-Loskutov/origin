#include <string.h>
#include "Centaur.h"
Centaur::Centaur() : Vehicle(true, "Кентавр", 15, 8, 2, 0, 0) {}

double Centaur::get_time(double range) {
	double time = 0;
	time = range / speed;
	double temp1 = time / run_time;
	double temp2 = static_cast<double>(static_cast<int>(time / run_time));
	unsigned rest_number = static_cast<int>(temp1);
	if (temp1 - temp2 == 0) {
		rest_number--;
	}
	else {
		nullptr;
	}
	time = time + rest_number  * rest_time1;
	return time;
}
