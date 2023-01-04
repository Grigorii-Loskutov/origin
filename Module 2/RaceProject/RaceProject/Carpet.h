#pragma once
#pragma once
#include <string>
#include "Vehicle.h"

class Carpet :public Vehicle {
public:
	Carpet();
	virtual void calc_time(double range) override;
};