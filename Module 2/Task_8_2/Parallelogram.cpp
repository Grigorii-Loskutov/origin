#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure_Creation_Except.h"
#include "Parallelogram.h"

Parallelogram::Parallelogram(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle("��������������", a, b, c, d, A, B, C, D) {
	if ((A != C) or (B != D)) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(������� " << a << ", " << b << ", " << c << ", " << d << "; ���� " << A << ", " << B << ", " << C << ", " << D << ") �� ��� ������. ";
		ss << "�������: ���� A,C � B,D ������� �� �����";
		throw Figure_Creation_Except(ss.str());
	}
	if ((a != c) or (b != d)) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(������� " << a << ", " << b << ", " << c << ", " << d << "; ���� " << A << ", " << B << ", " << C << ", " << D << ") �� ��� ������. ";
		ss << "�������: ������� a,c � b,d ������� �� �����";
		throw Figure_Creation_Except(ss.str());
	}

}
