#pragma once
#include <string>
#include "Vehicle.h"

class Boots :public Vehicle {
public:
	Boots();
	virtual void calc_time(double range) override;
};