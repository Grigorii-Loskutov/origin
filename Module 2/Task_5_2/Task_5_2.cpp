// Task_5_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>

class Figure {
protected:
	unsigned side_count;
	std::string name;
	double a, b, c, d;
	double A, B, C, D;
public:
	Figure(unsigned side_count, std::string name, double a, double b, double c, double d, double A, double B, double C, double D) {
		this->side_count = side_count;
		this->name = name;
		this->a = a; this->b = b; this->c = c; this->d = d;
		this->A = A; this->B = B; this->C = C, this->D = D;
	}
	Figure() {
		this->side_count = 0;
		this->name = "Default figure";
		this->a = 0; this->b = 0; this->c = 0; this->d = 0;
		this->A = 0; this->B = 0; this->C = 0; this->D = 0;
	}
	unsigned get_side_count() {
		return side_count;
	}
	std::string get_name() {
		return name;
	}
	double get_a() {
		return a;
	}
	double get_b() {
		return b;
	}
	double get_c() {
		return c;
	}
	double get_d() {
		return d;
	}
	double get_A() {
		return A;
	}
	double get_B() {
		return B;
	}
	double get_C() {
		return C;
	}
	double get_D() {
		return D;
	}
};
class Triangle :public Figure {
public:
	Triangle() : Figure(3, "Default Triangle", 1, 1, 1, 0, 60, 60, 60, 0) {}
	Triangle(std::string name, double a, double b, double c, double A, double B, double C) : Figure(3, name, a, b, c, 0, A, B, C, 0) {}

};

class Quadrangle :public Figure {
public:
	Quadrangle() : Figure(4, "Default Quadrangle", 1, 1, 1, 1, 90, 90, 90, 90) {}
	Quadrangle(std::string name, double a, double b, double c, double d, double A, double B, double C, double D) : Figure(4, name, a, b, c, d, A, B, C, D) {}

};

class Rectangular_Triangle :public Triangle{
public:
	Rectangular_Triangle(double a, double b, double c, double A, double B) : Triangle("Прямоугольный треугольник", a, b, c, A, B, 90) {}
};


class Isosceles_Triangle :public Triangle {
public:
	Isosceles_Triangle(double a, double b, double A, double B) : Triangle("Равнобедренный треугольник", a, b, a, A, B, A) {}
};

class Equilateral_Triangle :public Triangle {
public:
	Equilateral_Triangle(double a) : Triangle("Равносторонний треугольник", a, a, a, 60, 60, 60) {}
};

class Rectangle_ :public Quadrangle {
public:
	Rectangle_(double a, double b) : Quadrangle("Прямоугольник", a, b, a, b, 90, 90, 90, 90) {}
};

class Square :public Quadrangle {
public:
	Square(double a) : Quadrangle("Квадрат", a, a, a, a, 90, 90, 90, 90) {}
};

class Parallelogram :public Quadrangle {
public:
	Parallelogram(double a, double b, double A, double B) : Quadrangle("Параллелограмм", a, b, a, b, A, B, A, B) {}
};

class Rhombus :public Quadrangle {
public:
	Rhombus(double a, double A, double B) : Quadrangle("Ромб", a, a, a, a, A, B, A, B) {}
};

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
	Rectangle_ fig6(10,20);  // почему-то имя Кусефтпде занято...
	print_info(&fig6);
	Square fig7(20);
	print_info(&fig7);
	Parallelogram fig8(20, 30, 30, 40);
	print_info(&fig8);
	Rhombus fig9(30, 30, 40);
	print_info(&fig9);
}