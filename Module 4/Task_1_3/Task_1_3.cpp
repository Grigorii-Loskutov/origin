// Task_1_3.cpp :  Задача 3*. Операции над углами
// https://github.com/netology-code/cppl-homeworks/tree/main/01/03

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector<double> angles = { 0, 30, 45, 90 };
	std::vector < std::function<void(double)>> functions = { [](double angel) {std::cout << "sin: " << std::sin(3.1415926 * angel / 180); } ,[](double angel) {std::cout << "cos: " << std::cos(3.1415926 * angel / 180); } };
	//functions.emplace_back([](double angel) {std::cout << "sin: " << std::sin(3.1415926 * angel / 180); });
	//functions.emplace_back([](double angel) {std::cout << "cos: " << std::cos(3.1415926 * angel / 180); });
	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}
}

