#include <string.h>
#include "Triangle.h"


Triangle::Triangle() : Figure(3, "Default Triangle", 1, 1, 1, 0, 60, 60, 60, 0) {}
Triangle::Triangle(std::string name, double a, double b, double c, double A, double B, double C) : Figure(3, name, a, b, c, 0, A, B, C, 0) {}