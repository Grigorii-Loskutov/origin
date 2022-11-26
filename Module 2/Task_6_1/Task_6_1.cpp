﻿// Task_6_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include "math_func.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double N1 = 0, N2 = 0;
	unsigned short operation = 0;
	std::cout << "Введите первое число: "; std::cin >> N1;
	std::cout << "Введите второе число: "; std::cin >> N2;
	std::cout << "Выберите операцию(1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в целую (!) степень) : ";
	std::cin >> operation;
	math_func calc1;
	switch (operation)
	{
	case 1:
		std::cout << N1 << " + " << N2 << " = " << calc1.sum(N1,N2);
		break;
	case 2:
		std::cout << N1 << " - " << N2 << " = " << calc1.sub(N1, N2);
		break;
	case 3:
		std::cout << N1 << " * " << N2 << " = " << calc1.mult(N1, N2);
		break;
	case 4:
		std::cout << N1 << " / " << N2 << " = " << calc1.div(N1, N2);
		break;
	case 5:
		std::cout << N1 << " в степени " << N2 << " = " << calc1.pow(N1, N2);
		break;

	default:
		std::cout << "Не выбрана ни одна из операций";
		break;
	}
}

