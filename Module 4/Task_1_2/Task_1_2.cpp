// Task_1_2.cpp : Задача 2. std::variant
// https://github.com/netology-code/cppl-homeworks/tree/main/01/02

#include <iostream>
#include <vector>
#include <algorithm>
#include <variant>
#include <windows.h>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{	
	auto result = get_variant();
	if (std::holds_alternative<int>(result) == true) {
		std::cout << std::get<int>(result) * 2;
	}
	else if (std::holds_alternative<std::string>(result) == true)
	{
		std::cout << std::get<std::string>(result);
	}
	else if (std::holds_alternative<std::vector<int>>(result) == true)
	{
		std::for_each(std::get<std::vector<int>>(result).begin(), std::get<std::vector<int>>(result).end(), [](int& n) {std::cout << n << " "; });
	}
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
