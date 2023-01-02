#pragma once
#include <string>
#include "Vehicle.h"

class Eagle :public Vehicle {
public:
	Eagle();
	virtual double get_time(double range) override;
};