// Task_5_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>

class Figure {
protected:
	unsigned side_count;
	std::string name;
public:
	Figure(unsigned side_count, std::string name) {
		this->side_count = side_count;
		this->name = name;
	}
	Figure() {
		this->side_count = 0;
		this->name = "Фигура";
	}
	unsigned get_side_count() {
		return side_count;
	}
	std::string get_name() {
		return name;
	}
};

class Triangle :public Figure {
public:
	Triangle() : Figure(3, "Треугольник") {}
};

class Quadrangle:public Figure {
public:
	Quadrangle() : Figure(4, "Четырёхугольник") {}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Figure fig1;
	Triangle fig2;
	Quadrangle fig3;
	std::cout << "Количество сторон:\n";
	std::cout << fig1.get_name() << ": " << fig1.get_side_count() << "\n";
	std::cout << fig2.get_name() << ": " << fig2.get_side_count() << "\n";
	std::cout << fig3.get_name() << ": " << fig3.get_side_count() << "\n";
}