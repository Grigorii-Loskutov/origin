#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure_Creation_Except.h"
#include "Isosceles_Triangle.h"

Isosceles_Triangle::Isosceles_Triangle(double a, double b, double c, double A, double B, double C) : Triangle("–авнобедренный треугольник", a, b, c, A, B, C) {
	if (C != A) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(стороны " << a << ", " << b << ", " << c << "; углы " << A << ", " << B << ", " << C << ") не был создан. ";
		ss << "ѕричина: угол A не равен углу B";
		throw Figure_Creation_Except(ss.str());
	}
	if (c != a) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(стороны " << a << ", " << b << ", " << c << "; углы " << A << ", " << B << ", " << C << ") не был создан. ";
		ss << "ѕричина: сторна a не равна стороне с";
		throw Figure_Creation_Except(ss.str());
	}
}
