#pragma once
#include <string>
#include "Vehicle.h"

class Broom :public Vehicle {
public:
	Broom();
	virtual double get_time(double range) override;
};