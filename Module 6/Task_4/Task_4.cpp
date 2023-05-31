// Task_4.cpp : https://github.com/netology-code/map-homeworks/tree/main/04
// Домашнее задание к занятию «Рефакторинг»

#include <iostream>
#include <windows.h>
#include "shape.h"
#include "transform.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Shape line(shapeType::Line, 9);
	line.get_type();
	transform transform_line(line);
	Shape l2 = transform_line.shift(1, 1, 1);
	Shape l3 = transform_line.scaleX(2);
	return 0;
}