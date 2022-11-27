#include <string.h>
#include "Quadrangle.h"

Quadrangle::Quadrangle() : Figure(4, "Default Quadrangle", 1, 1, 1, 1, 90, 90, 90, 90) {}
Quadrangle::Quadrangle(std::string name, double a, double b, double c, double d, double A, double B, double C, double D) : Figure(4, name, a, b, c, d, A, B, C, D) {}
