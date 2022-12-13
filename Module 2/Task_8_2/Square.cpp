#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure_Creation_Except.h"
#include "Square.h"

Square::Square(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(" вадрат", a, a, a, a, 90, 90, 90, 90) {
	if ((A != 90) or (B != 90) or (C != 90) or (D != 90)) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(стороны " << a << ", " << b << ", " << c << ", " << d << "; углы " << A << ", " << B << ", " << C << ", " << D << ") не был создан. ";
		ss << "ѕричина: один из углов не равен 90 гр.";
		throw Figure_Creation_Except(ss.str());
	}
	if ((a != c) or (a != b) or (a != c) or (a != d)) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(стороны " << a << ", " << b << ", " << c << ", " << d << "; углы " << A << ", " << B << ", " << C << ", " << D << ") не был создан. ";
		ss << "ѕричина: стороны не равны между собой";
		throw Figure_Creation_Except(ss.str());
	}
}
