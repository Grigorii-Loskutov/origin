#include <string.h>
#include "Broom.h"
Broom::Broom() : Vehicle(false, "Метла", 20, 0, 0, 0, 0) {}

double Broom::get_time(double range) {
	double time = 0;
	unsigned k = static_cast<int>(range / 1000);
	time = range / speed;
	if (k != 0) {
		time = time * (100 - k) / 100;
	}
	return time;
}
