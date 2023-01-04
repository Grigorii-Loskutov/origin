#pragma once
#include <string>
#include "Vehicle.h"

class Camel :public Vehicle {
public:
	Camel();
	virtual void calc_time(double range) override;
};