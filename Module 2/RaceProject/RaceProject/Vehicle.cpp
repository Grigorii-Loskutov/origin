#include "Vehicle.h"
Vehicle::Vehicle(bool ground, std::string name, double speed, double run_time, double rest_time1, double rest_time2, double rest_time3) {
	this->ground = ground;
	this->name = name;
	this->speed = speed;
	this->run_time = run_time;
	this->rest_time1 = rest_time1;
	this->rest_time2 = rest_time2;
	this->rest_time3 = rest_time3;
}
Vehicle::Vehicle() {
	this->name = "Default Vehicle";
	this->ground = true;
	this->speed = 1;
}
double Vehicle::get_time(double time) {
	return range / time; //Что возвращать для базового класса?
}
std::string Vehicle::get_name() {
	return name;
}