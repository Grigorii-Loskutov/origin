#pragma once
#include <string>

class Figure {
protected:
	unsigned side_count;
	std::string name;
	double a, b, c, d;
	double A, B, C, D;
public:
	Figure(unsigned side_count, std::string name, double a, double b, double c, double d, double A, double B, double C, double D);
	Figure();
	unsigned get_side_count();
	std::string get_name();
	double get_a();
	double get_b();
	double get_c();
	double get_d();
	double get_A();
	double get_B();
	double get_C();
	double get_D();
};