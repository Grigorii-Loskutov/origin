#pragma once
#include <string>
#include "Vehicle.h"

class FastCamel :public Vehicle {
public:
	FastCamel();
	virtual double get_time(double range) override;
};