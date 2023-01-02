#pragma once
#include <string>
#include "Vehicle.h"

class Boots :public Vehicle {
public:
	Boots();
	virtual double get_time(double range) override;
};