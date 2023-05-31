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
	line = transform_line.shift(1, 1, 1);
	line = transform_line.scaleX(2);

	Shape rectangle(shapeType::Rectangle, 3, 3);
	transform transform_rec(rectangle);
	rectangle = transform_rec.shift(1, 1, 1);

	Shape parallelepiped(shapeType::Parallelepiped, 3, 3, 3);
	transform transform_par(rectangle);
	parallelepiped = transform_par.shift(1, 1, 1);
	parallelepiped = transform_par.scaleX(2);
	parallelepiped = transform_par.scaleY(2);
	parallelepiped = transform_par.scaleZ(2);
	parallelepiped = transform_par.scale(0.5);
	Shape line2 = line;
	return 0;
}