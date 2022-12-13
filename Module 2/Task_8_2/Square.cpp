#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure_Creation_Except.h"
#include "Square.h"

Square::Square(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle("�������", a, a, a, a, 90, 90, 90, 90) {
	if ((A != 90) or (B != 90) or (C != 90) or (D != 90)) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(������� " << a << ", " << b << ", " << c << ", " << d << "; ���� " << A << ", " << B << ", " << C << ", " << D << ") �� ��� ������. ";
		ss << "�������: ���� �� ����� �� ����� 90 ��.";
		throw Figure_Creation_Except(ss.str());
	}
	if ((a != c) or (a != b) or (a != c) or (a != d)) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(������� " << a << ", " << b << ", " << c << ", " << d << "; ���� " << A << ", " << B << ", " << C << ", " << D << ") �� ��� ������. ";
		ss << "�������: ������� �� ����� ����� �����";
		throw Figure_Creation_Except(ss.str());
	}
}
