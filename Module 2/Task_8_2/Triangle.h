#pragma once
#include <string>
#include "Figure.h"
class Triangle :public Figure {
public:
	Triangle();
	Triangle(std::string name, double a, double b, double c, double A, double B, double C);

};