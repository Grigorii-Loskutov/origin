// Task_6_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>
#include "Figure.h"
#include "Triangle.h"
#include "Quadrangle.h"
#include "Rectangular_Triangle.h"
#include "Isosceles_Triangle.h"
#include "Equilateral_Triangle.h"
#include "Rectangle_.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

void print_info(Figure* figure) {
	if (figure->get_side_count() == 3) {
		std::cout << "\n";
		std::cout << figure->get_name();
		std::cout << "\nСтороны: " << "a = " << figure->get_a() << " b = " << figure->get_b() << " c = " << figure->get_c();
		std::cout << "\nУглы: " << "A = " << figure->get_A() << " B = " << figure->get_B() << " C = " << figure->get_C();
		std::cout << "\n";
	}
	else {
		std::cout << "\n";
		std::cout << figure->get_name();
		std::cout << "\nСтороны: " << "a = " << figure->get_a() << " b = " << figure->get_b() << " c = " << figure->get_c() << " d = " << figure->get_d();
		std::cout << "\nУглы: " << "A = " << figure->get_A() << " B = " << figure->get_B() << " C = " << figure->get_C() << " D = " << figure->get_D();
		std::cout << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Triangle fig1("Треугольник", 10, 20, 30, 50, 60, 70);
	print_info(&fig1);
	Rectangular_Triangle fig2(10, 20, 30, 50, 60);
	print_info(&fig2);
	Isosceles_Triangle fig3(10, 20, 50, 60);
	print_info(&fig3);
	Equilateral_Triangle fig4(30);
	print_info(&fig4);
	Quadrangle fig5("Четырехугольник", 10, 20, 30, 40, 50, 60, 70, 80);
	print_info(&fig5);
	Rectangle_ fig6(10, 20);  // почему-то имя Rectangle занято...
	print_info(&fig6);
	Square fig7(20);
	print_info(&fig7);
	Parallelogram fig8(20, 30, 30, 40);
	print_info(&fig8);
	Rhombus fig9(30, 30, 40);
	print_info(&fig9);
}