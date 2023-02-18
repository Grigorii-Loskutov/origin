﻿// Task_2_1.cpp : Задача 1. Программа с ошибками
// https://github.com/netology-code/cppl-homeworks/tree/main/02/01

#include <iostream>
using namespace std;

struct point {
public:
	double m_x;
	double m_y;
	point(double x, double y) {
		this->m_x = x;
		this->m_y = y;
	}
};

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: " << point_object.m_y << std::endl;
}

int main()
{
	int i;
	for (i = 0; i < 5; i++) {
		point my_point(i, 2 * i);
		print_point(my_point);
	}
	return 0;
}