#include <string.h>
#include <iostream>
#include <sstream>
#include "Triangle.h"
#include "Figure_Creation_Except.h"

Triangle::Triangle() : Figure(3, "Default Triangle", 1, 1, 1, 0, 60, 60, 60, 0) {}
Triangle::Triangle(std::string name, double a, double b, double c, double A, double B, double C)  :  Figure::Figure(3, name, a, b, c, 0, A, B, C, 0) {
	
	if ((A + B + C) != 180) {
		std::stringstream ss;
		ss << "\n";
		ss << name << "(������� " << a << ", " << b << ", " << c << "; ���� " << A << ", " << B << ", " << C << ") �� ��� ������. ";
		ss << "�������: ����� ����� �� ����� 180";
		throw Figure_Creation_Except(ss.str());
	}
	
}