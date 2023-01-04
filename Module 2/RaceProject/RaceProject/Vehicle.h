#pragma once
#include <string>

class Vehicle {
protected:
	bool ground;
	unsigned speed;
	std::string name;
	double run_time;
	double rest_time1;
	double rest_time2;
	double rest_time3;
	double time;
public:
	Vehicle();
	Vehicle(bool ground, std::string name, double speed, double run_time, double rest_time1, double rest_time2, double rest_time3);
	double get_time();
	std::string get_name();
	virtual void calc_time(double range);
};