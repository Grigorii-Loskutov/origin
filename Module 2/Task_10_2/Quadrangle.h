#pragma once
#include <string.h>
#include "Figure.h"

class Quadrangle :public Figure {
public:
	Quadrangle();
	Quadrangle(std::string name, double a, double b, double c, double d, double A, double B, double C, double D);

};