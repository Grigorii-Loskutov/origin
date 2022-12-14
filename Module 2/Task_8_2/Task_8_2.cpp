// Task_8_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <string.h>
#include <exception>

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
#include "Figure_Creation_Except.h"

//class Figure_Creation_Fail :public std::domain_error{
//private:
//	const char* what() const override { return "Создание фигуры с неподходящими параметрами"; }
//public:
//	Figure_Creation_Fail(std::string error) : std::domain_error(error) {}
//};

//class Figure_Creation_Fail :public std::domain_error {
//private:
//	std::string err; 
//public:
//	Figure_Creation_Fail(std::string error) : std::domain_error(error) {}
//	virtual const char* what() const override
//	{
//		return err.c_str();
//	}
//};

void print_info(Figure* figure) {
	if (figure->get_side_count() == 3) {
		std::cout << "\n";
		std::cout << figure->get_name();
		std::cout << "\nСтороны: " << "a = " << figure->get_a() << " b = " << figure->get_b() << " c = " << figure->get_c();
		std::cout << "\nУглы: " << "A = " << figure->get_A() << " B = " << figure->get_B() << " C = " << figure->get_C();
		std::cout << "\n";
	}
	if (figure->get_side_count() == 0) {
		std::cout << "\n";
		std::cout << figure->get_name();
		std::cout << "\nСтороны: нет";
		std::cout << "\nУглы: нет";
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

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Базовая фигура
	try {
		Figure fig0(3, "Фигура", 10, 20, 30, 10, 50, 60, 70, 90);
		print_info(&fig0);
	}
	catch (const Figure_Creation_Except& ex) { std::cout << ex.what() << "\n"; }

	try {
		Figure fig0(0, "Фигура", 10, 20, 30, 10, 50, 60, 70, 90);
		print_info(&fig0);
	}
	catch (const Figure_Creation_Except& ex) { std::cout << ex.what() << "\n"; }

	//Треугольник
	try {
		Triangle fig1("Треугольник", 10, 20, 30, 50, 60, 70);
		print_info(&fig1);
	}
	catch (const Figure_Creation_Except& ex) { std::cout << ex.what() << "\n"; }
	
	try {
		Triangle fig1("Треугольник", 10, 20, 30, 50, 59, 70);
		print_info(&fig1);
	}
	catch (const Figure_Creation_Except& ex) { std::cout << ex.what() << "\n"; }

	//Прямоугольный треугольник
	try {
		Rectangular_Triangle fig2(10, 20, 30, 50, 60, 90);
		print_info(&fig2);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Rectangular_Triangle fig2(10, 20, 30, 50, 39, 90);
		print_info(&fig2);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }
	
	try {
		Rectangular_Triangle fig2(10, 20, 30, 50, 40, 90);
		print_info(&fig2);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	//Равнобедренный треугольник
	try {
		Isosceles_Triangle fig3(10, 20, 10, 50, 79, 50);
		print_info(&fig3);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Isosceles_Triangle fig3(10, 20, 9, 50, 80, 50);
		print_info(&fig3);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Isosceles_Triangle fig3(10, 20, 10, 50, 80, 50);
		print_info(&fig3);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	//Равносторонний треугольник
	try {
		Equilateral_Triangle fig4(10, 10, 10, 60, 61, 59);
		print_info(&fig4);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Equilateral_Triangle fig4(10, 10, 10, 60, 60, 59);
		print_info(&fig4);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Equilateral_Triangle fig4(10, 10, 9, 60, 60, 60);
		print_info(&fig4);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Equilateral_Triangle fig4(10, 10, 10, 60, 60, 60);
		print_info(&fig4);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	//Четырёхугольник
	try {
		Quadrangle fig5("Четырехугольник", 10, 20, 30, 40, 50, 60, 70, 80);
		print_info(&fig5);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Quadrangle fig5("Четырехугольник", 10, 20, 30, 40, 50, 130, 70, 110);
		print_info(&fig5);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	//Прямоугольник

	try {
		Rectangle_ fig6(10, 20, 10, 20, 50, 130, 70, 110);
		print_info(&fig6);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Rectangle_ fig6(10, 20, 11, 20, 90, 90, 90, 90);
		print_info(&fig6);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	//Квадрат
	try {
		Square fig7(10, 20, 10, 20, 90, 90, 90, 90);
		print_info(&fig7);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Square fig7(10, 10, 10, 10, 90, 90, 89, 91);
		print_info(&fig7);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Square fig7(10, 10, 10, 10, 90, 90, 90, 90);
		print_info(&fig7);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	//Параллелограмм
	
	try {
		Parallelogram fig8(10, 20, 11, 20, 70, 110, 70, 110);
		print_info(&fig8);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Parallelogram fig8(10, 20, 10, 20, 70, 111, 69, 110);
		print_info(&fig8);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Parallelogram fig8(10, 20, 10, 20, 70, 111, 70, 110);
		print_info(&fig8);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Parallelogram fig8(10, 20, 10, 20, 70, 110, 70, 110);
		print_info(&fig8);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	//Робм

	try {
		Rhombus fig9(10, 10, 10, 11, 70, 110, 70, 110);
		print_info(&fig9);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Rhombus fig9(10, 10, 10, 11, 70, 111, 69, 110);
		print_info(&fig9);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Rhombus fig9(10, 10, 10, 11, 70, 111, 70, 110);
		print_info(&fig9);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }

	try {
		Rhombus fig9(10, 10, 10, 10, 70, 110, 70, 110);
		print_info(&fig9);
	}
	catch (const Figure_Creation_Except& ex) { std::cerr << ex.what() << "\n"; }
}
