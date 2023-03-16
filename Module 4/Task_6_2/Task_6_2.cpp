// Task_6_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введите кол-во элементов: ";
	int N{ 0 }, temp{ 0 };
	std::cin >> N;
	std::set<int> my_set;
	for (unsigned iter = 0; iter < N; iter++) {
		std::cout << "Введите элемент [" << iter + 1 << "]: ";
		std::cin >> temp;
		my_set.emplace(temp);
	}
	auto print = [](auto& n) { std::cout << n << "\n"; };
	std::for_each(my_set.rbegin(), my_set.rend(), print);
}