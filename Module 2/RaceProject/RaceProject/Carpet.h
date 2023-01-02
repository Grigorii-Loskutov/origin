#pragma once
#pragma once
#include <string>
#include "Vehicle.h"

class Carpet :public Vehicle {
public:
	Carpet();
	virtual double get_time(double range) override;
};