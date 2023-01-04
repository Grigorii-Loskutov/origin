#include <string.h>
#include "Eagle.h"
Eagle::Eagle() : Vehicle(false, "Îð¸ë", 10, 0, 0, 0, 0) {}

void Eagle::calc_time(double range) {
	time = (range / speed) * 0.96;
}
