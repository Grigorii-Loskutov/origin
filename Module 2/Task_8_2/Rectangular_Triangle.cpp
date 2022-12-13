#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure_Creation_Except.h"
#include "Rectangular_Triangle.h"

Rectangular_Triangle::Rectangular_Triangle(double a, double b, double c, double A, double B, double C) : Triangle("������������� �����������", a, b, c, A, B, C) {
	if (C != 90) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(������� " << a << ", " << b << ", " << c << "; ���� " << A << ", " << B << ", " << C << ") �� ��� ������. ";
		ss << "�������: ���� C �� ����� 90 ��������";
		throw Figure_Creation_Except(ss.str());
	}
}