#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure_Creation_Except.h"
#include "Quadrangle.h"

Quadrangle::Quadrangle() : Figure(4, "Default Quadrangle", 1, 1, 1, 1, 90, 90, 90, 90) {}
Quadrangle::Quadrangle(std::string name, double a, double b, double c, double d, double A, double B, double C, double D) : Figure(4, name, a, b, c, d, A, B, C, D) {
	if ((A + B + C + D) != 360) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(������� " << a << ", " << b << ", " << c << ", " << d << "; ���� " << A << ", " << B << ", " << C << ", " << D << ") �� ��� ������. ";
		ss << "�������: ����� ����� �� ����� 360";
		throw Figure_Creation_Except(ss.str());
	}
}
