#pragma once
#include <string>
#include "Vehicle.h"

class Eagle :public Vehicle {
public:
	Eagle();
	virtual void calc_time(double range) override;
};