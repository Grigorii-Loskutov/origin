﻿#include <string.h>
#include <iostream>
#include <sstream>
#include "Figure.h"
#include "Figure_Creation_Except.h"

Figure::Figure(unsigned side_count, std::string name, double a, double b, double c, double d, double A, double B, double C, double D) {
	if (name == "Фигура" and side_count != 0) {
		std::stringstream ss;
		ss << name << "(стороны " << a << ", " << b << ", " << c << "; углы " << A << ", " << B << ", " << C << ") не был создан. ";
		ss << "Причина: количество сторон больше 0";
		throw Figure_Creation_Except(ss.str());
	}
	else if (name == "Фигура" and side_count == 0) {
		this->side_count = 0;
		this->name = "Фигура";
		this->a = 0; this->b = 0; this->c = 0; this->d = 0;
		this->A = 0; this->B = 0; this->C = 0; this->D = 0;
	}
	else 
	{
		this->side_count = side_count;
		this->name = name;
		this->a = a; this->b = b; this->c = c; this->d = d;
		this->A = A; this->B = B; this->C = C, this->D = D;
	}
}
Figure::Figure() {
	this->side_count = 0;
	this->name = "Default figure";
	this->a = 0; this->b = 0; this->c = 0; this->d = 0;
	this->A = 0; this->B = 0; this->C = 0; this->D = 0;
}
unsigned Figure::get_side_count() {
	return side_count;
}
std::string Figure::get_name() {
	return name;
}
double Figure::get_a() {
	return a;
}
double Figure::get_b() {
	return b;
}
double Figure::get_c() {
	return c;
}
double Figure::get_d() {
	return d;
}
double Figure::get_A() {
	return A;
}
double Figure::get_B() {
	return B;
}
double Figure::get_C() {
	return C;
}
double Figure::get_D() {
	return D;
}