#pragma once
#include <string>
#include "Vehicle.h"

class Centaur :public Vehicle {
public:
	Centaur();
	virtual void calc_time(double range) override;
};