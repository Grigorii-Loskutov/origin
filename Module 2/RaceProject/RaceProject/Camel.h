#pragma once
#include <string>
#include "Vehicle.h"

class Camel :public Vehicle {
public:
	Camel();
	virtual double get_time(double range) override;
};