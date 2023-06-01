// Task_4.cpp : https://github.com/netology-code/map-homeworks/tree/main/04
// Домашнее задание к занятию «Рефакторинг»

#include <iostream>
#include <vector>

#include <windows.h>

#include "shape.h"


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Line l1 = Line(3);
	l1.shift(1, 1, 1);
	Cylinder c1 = Cylinder(2, 5);
	c1.shift(2, 2, 2);
	return 0;
}