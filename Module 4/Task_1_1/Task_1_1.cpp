// Task_1_1.cpp : Задача 1. Лямбда-функция
// https://github.com/netology-code/cppl-homeworks/tree/main/01/01

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector<int> arr1 = { 4, 7, 9, 14, 12 };
	std::cout << "\nВходные данные:";
	auto print = [](const int& n) { std::cout << " " << n; };
	std::for_each(arr1.begin(), arr1.end(), print);
	int iter = 0;
	std::for_each(arr1.begin(), arr1.end(), [&iter](int& n) { if (0 == (iter + 1) % 2) { n *= 3; } iter++; });
	std::cout << "\nВыходные данные: ";
	std::for_each(arr1.begin(), arr1.end(), print);

}

