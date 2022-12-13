#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure_Creation_Except.h"
#include "Isosceles_Triangle.h"

Isosceles_Triangle::Isosceles_Triangle(double a, double b, double c, double A, double B, double C) : Triangle("�������������� �����������", a, b, c, A, B, C) {
	if (C != A) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(������� " << a << ", " << b << ", " << c << "; ���� " << A << ", " << B << ", " << C << ") �� ��� ������. ";
		ss << "�������: ���� A �� ����� ���� B";
		throw Figure_Creation_Except(ss.str());
	}
	if (c != a) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(������� " << a << ", " << b << ", " << c << "; ���� " << A << ", " << B << ", " << C << ") �� ��� ������. ";
		ss << "�������: ������ a �� ����� ������� �";
		throw Figure_Creation_Except(ss.str());
	}
}
