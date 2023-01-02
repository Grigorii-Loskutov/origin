#include <string.h>
#include "Eagle.h"
Eagle::Eagle() : Vehicle(false, "Àð¸ë", 10, 0, 0, 0, 0) {}

double Eagle::get_time(double range) {
	double time = 0;
	time = (range / speed) * 0.96;
	return time;
}
