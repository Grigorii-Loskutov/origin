#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure_Creation_Except.h"
#include "Rectangular_Triangle.h"

Rectangular_Triangle::Rectangular_Triangle(double a, double b, double c, double A, double B, double C) : Triangle("Прямоугольный треугольник", a, b, c, A, B, C) {
	if (C != 90) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(стороны " << a << ", " << b << ", " << c << "; углы " << A << ", " << B << ", " << C << ") не был создан. ";
		ss << "Причина: угол C не равен 90 градусам";
		throw Figure_Creation_Except(ss.str());
	}
}