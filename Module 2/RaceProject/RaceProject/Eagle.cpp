#include <string.h>
#include "Eagle.h"
Eagle::Eagle() : Vehicle(false, "Орёл", 8, 0, 0, 0, 0) {}

void Eagle::calc_time(double range) {
	time = (range / speed) * 0.94;
}
