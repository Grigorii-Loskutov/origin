// Task_5_3.cpp : Defines the entry point for the console application.
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
	virtual bool check() {
		if (side_count == 0) {
			return 1;
		}
		else return 0;
	}
	Figure(unsigned side_count, std::string name, double a, double b, double c, double d, double A, double B, double C, double D) {
		this->side_count = side_count;
		this->name = name;
		this->a = a; this->b = b; this->c = c; this->d = d;
		this->A = A; this->B = B; this->C = C, this->D = D;
	}
	Figure() {
		this->side_count = 0;
		this->name = "Фигура";
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
	/*void print_info() {
		std::cout << "\n";
		std::cout << name << ":";
		if (check() == true) {
			std::cout << "\nПравильная";
		}
		else {
			std::cout << "\nНеправильная";
		}
		std::cout << "\nКоличество сторон: " << side_count;
		if (side_count == 3) {
			std::cout << "\nСтороны: " << "a = " << a << " b = " << b << " c = " << c;
			std::cout << "\nУглы: " << "A = " << A << " B = " << B << " C = " << C;
			std::cout << "\n";
		}
		else if (side_count == 4) {
			std::cout << "\nСтороны: " << "a = " << a << " b = " << b << " c = " << c << " d = " << d;
			std::cout << "\nУглы: " << "A = " << A << " B = " << B << " C = " << C << " D = " << D;
			std::cout << "\n";
		}
		else {
			NULL;
		}
		std::cout << "\n";
	}*/
};

void print_figure(Figure* fig) {
	std::cout << "\n";
	std::cout << fig->get_name() << ":";
	if (fig->check() == true) {
		std::cout << "\nПравильная";
	}
	else {
		std::cout << "\nНеправильная";
	}
	std::cout << "\nКоличество сторон: " << fig->get_side_count();
	if (fig->get_side_count() == 3) {
		std::cout << "\nСтороны: " << "a = " << fig->get_a() << " b = " << fig->get_b() << " c = " << fig->get_c();
		std::cout << "\nУглы: " << "A = " << fig->get_A() << " B = " << fig->get_B() << " C = " << fig->get_C();
		std::cout << "\n";
	}
	else if (fig->get_side_count() == 4) {
		std::cout << "\nСтороны: " << "a = " "a = " << fig->get_a() << " b = " << fig->get_b() << " c = " << fig->get_c() << " d = " << fig->get_d();
		std::cout << "\nУглы: " << "A = " << fig->get_A() << " B = " << fig->get_B() << " C = " << fig->get_C()<< " D = " << fig->get_D();
		std::cout << "\n";
	}
	else {
		NULL;
	}
	std::cout << "\n";
}
class Triangle :public Figure {
public:
	Triangle() : Figure(3, "Default Triangle", 1, 1, 1, 0, 60, 60, 60, 0) {}
	Triangle(std::string name, double a, double b, double c, double A, double B, double C) : Figure(3, name, a, b, c, 0, A, B, C, 0) {}
	bool check() override {
		if ((side_count == 3) && ((A + B + C) == 180)) {
			return 1;
		}
		else return 0;
	}
};

class Quadrangle :public Figure {
public:
	Quadrangle() : Figure(4, "Default Quadrangle", 1, 1, 1, 1, 90, 90, 90, 90) {}
	Quadrangle(std::string name, double a, double b, double c, double d, double A, double B, double C, double D) : Figure(4, name, a, b, c, d, A, B, C, D) {}
	bool check() override {
		if ((side_count == 4) && ((A + B + C + D) == 360)) {
			return 1;
		}
		else return 0;
	}

};

class Rectangular_Triangle :public Triangle {
public:
	Rectangular_Triangle(double a, double b, double c, double A, double B, double C) : Triangle("Прямоугольный треугольник", a, b, c, A, B, C) {}
	bool check() override {
		if ((180 == (A + B + C)) && (C == 90)) {
			return 1;
		}
		else return 0;
	}
};


class Isosceles_Triangle :public Triangle {
public:
	Isosceles_Triangle(double a, double b, double c, double A, double B, double C) : Triangle("Равнобедренный треугольник", a, b, c, A, B, C) {}
	bool check() override {
		if ((180 == (A + B + C)) && (A == C) && (a = c)) {
			return 1;
		}
		else return 0;
	}
};

class Equilateral_Triangle :public Triangle {
public:
	Equilateral_Triangle(double a, double b, double c, double A, double B, double C) : Triangle("Равносторонний треугольник", a, b, c, A, B, C) {}
	bool check() override {
		if ((a == b) && (a == c) && (b == c) && (60 == A) && (60 == B) && (60 == C)) {
			return 1;
		}
		else return 0;
	}
};

class Rectangle_ :public Quadrangle {
public:
	Rectangle_(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle("Прямоугольник", a, b, c, d, A, B, C, D) {}
	bool check() override {
		if ((a == c) && (b == d) && (A == 90) && (B == 90) && (C == 90) && (D == 90)) {
			return 1;
		}
		else return 0;
	}
};

class Square :public Quadrangle {
public:
	Square(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle("Квадрат", a, b, c, d, A, B, C, D) {}
	bool check() override {
		if ((a == b) && (b == c) && (c == d) && (A == 90) && (B == 90) && (C == 90) && (D == 90)) {
			return 1;
		}
		else return 0;
	}
};

class Parallelogram :public Quadrangle {
public:
	Parallelogram(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle("Параллелограмм", a, b, c, d, A, B, C, D) {}
	bool check() override {
		if ((a == b) && (c == d) && (A == C) && (B == D) && ((A + B + C + D) == 360)) {
			return 1;
		}
		else return 0;
	}
};

class Rhombus :public Quadrangle {
public:
	Rhombus(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle("Ромб", a, b, c, d, A, B, C, D) {}
	bool check() override {
		if ((a == b) && (b == c) && (c == d) && (A == C) && (B == D) && ((A + B + C + D) == 360)) {
			return 1;
		}
		else return 0;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure fig00;
	print_figure(&fig00);

	Triangle fig01("Треугольник", 10, 20, 30, 50, 60, 70);
	print_figure(&fig01);

	Rectangular_Triangle fig02(10, 20, 30, 50, 60, 90);
	print_figure(&fig02);

	Rectangular_Triangle fig03(10, 20, 30, 50, 40, 90);
	print_figure(&fig03);

	Isosceles_Triangle fig04(10, 20, 10, 50, 60, 50);
	print_figure(&fig04);

	Equilateral_Triangle fig05(30, 30, 30, 60, 60, 60);
	print_figure(&fig05);

	Quadrangle fig06("Четырехугольник", 10, 20, 30, 40, 50, 60, 70, 80);
	print_figure(&fig06);

	Rectangle_ fig07(10, 20, 10, 20, 90, 90, 90, 90);
	print_figure(&fig07);

	Square fig08(20, 20, 20, 20, 90, 90, 90, 90);
	print_figure(&fig08);;

	Parallelogram fig09(20, 30, 20, 30, 30, 40, 30, 40);
	print_figure(&fig09);

	Rhombus fig10(30, 30, 30, 30, 30, 40, 30, 40);
	print_figure(&fig10);
}

