#pragma once
#include <string>
#include "Vehicle.h"

class Broom :public Vehicle {
public:
	Broom();
	virtual void calc_time(double range) override;
};