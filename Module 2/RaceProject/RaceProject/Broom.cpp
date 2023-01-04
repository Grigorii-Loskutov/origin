#include <string.h>
#include "Broom.h"
Broom::Broom() : Vehicle(false, "Метла", 20, 0, 0, 0, 0) {}

void Broom::calc_time(double range) {
	unsigned k = static_cast<int>(range / 1000);
	time = range / speed;
	if (k != 0) {
		time = time * (100 - k) / 100;
	}
}
