﻿#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure_Creation_Except.h"
#include "Parallelogram.h"

Parallelogram::Parallelogram(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle("Параллелограмм", a, b, c, d, A, B, C, D) {
	if ((A != C) or (B != D)) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(стороны " << a << ", " << b << ", " << c << ", " << d << "; углы " << A << ", " << B << ", " << C << ", " << D << ") не был создан. ";
		ss << "Причина: углы A,C и B,D попарно не равны";
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
