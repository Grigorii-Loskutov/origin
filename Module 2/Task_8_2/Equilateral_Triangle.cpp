#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure_Creation_Except.h"
#include "Equilateral_Triangle.h"

Equilateral_Triangle::Equilateral_Triangle(double a, double b, double c, double A, double B, double C) : Triangle("–авносторонний треугольник", a, b, c, A, B, C) {
	if ((A != 60) or (B != 60) or (C != 60)) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(стороны " << a << ", " << b << ", " << c << "; углы " << A << ", " << B << ", " << C << ") не был создан. ";
		ss << "ѕричина: один из углов не равен 60 градусов";
		throw Figure_Creation_Except(ss.str());
	}
	if ((c != a) or (c != b) or (a != b)) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(стороны " << a << ", " << b << ", " << c << "; углы " << A << ", " << B << ", " << C << ") не был создан. ";
		ss << "ѕричина: стороны не равны между собой";
		throw Figure_Creation_Except(ss.str());
	}
}