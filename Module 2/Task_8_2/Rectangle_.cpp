#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure_Creation_Except.h"
#include "Rectangle_.h"

Rectangle_::Rectangle_(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle("�������������", a, b, c, d, A, B, C, D) {

	if ((A != 90) or (B != 90) or (C != 90) or (D != 90)) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(������� " << a << ", " << b << ", " << c << ", " << d << "; ���� " << A << ", " << B << ", " << C << ", " << D << ") �� ��� ������. ";
		ss << "�������: ���� �� ����� �� ����� 90 ��.";
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
