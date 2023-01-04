#pragma once
#include <string>
#include "Vehicle.h"

class FastCamel :public Vehicle {
public:
	FastCamel();
	virtual void calc_time(double range) override;
};