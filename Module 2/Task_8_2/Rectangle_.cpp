#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure_Creation_Except.h"
#include "Rectangle_.h"

Rectangle_::Rectangle_(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle("Прямоугольник", a, b, c, d, A, B, C, D) {

	if ((A != 90) or (B != 90) or (C != 90) or (D != 90)) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(стороны " << a << ", " << b << ", " << c << ", " << d << "; углы " << A << ", " << B << ", " << C << ", " << D << ") не был создан. ";
		ss << "Причина: один из углов не равен 90 гр.";
		throw Figure_Creation_Except(ss.str());
	}
	if ((a != c) or (b != d)) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(стороны " << a << ", " << b << ", " << c << ", " << d << "; углы " << A << ", " << B << ", " << C << ", " << D << ") не был создан. ";
		ss << "Причина: стороны a,c и b,d попарно не равны";
		throw Figure_Creation_Except(ss.str());
	}
}
