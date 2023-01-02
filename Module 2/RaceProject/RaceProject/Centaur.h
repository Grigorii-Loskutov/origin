#pragma once
#include <string>
#include "Vehicle.h"

class Centaur :public Vehicle {
public:
	Centaur();
	virtual double get_time(double range) override;
};