#pragma once
#include <string>

class Vehicle {
private:
	unsigned range;
protected:
	bool ground;
	unsigned speed;
	std::string name;
	double run_time;
	double rest_time1;
	double rest_time2;
	double rest_time3;

public:
	Vehicle();
	Vehicle(bool ground, std::string name, double speed, double run_time, double rest_time1, double rest_time2, double rest_time3);
	virtual double get_time(double range);
	std::string get_name();
};