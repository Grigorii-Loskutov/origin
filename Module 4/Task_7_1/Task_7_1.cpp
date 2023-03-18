// Task_7_1.cpp : https://github.com/netology-code/cppl-homeworks/tree/main/08/01
// Задача 1. Уникальный вектор

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <windows.h>

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "[IN]: ";
	std::vector<int> in_vec{ 1, 1, 2, 5, 6, 1, 2, 4 };
	auto print = [](auto& n) { std::cout << n << " "; };
	std::for_each(in_vec.rbegin(), in_vec.rend(), print);
	std::cout << "\n";
	std::cout << "[OUT]: ";
	std::set<int> out_set;
	std::vector<int>::const_iterator iter = in_vec.begin();
	while (iter != in_vec.end()) {
		out_set.insert(*iter);
		iter++;
	}
	std::for_each(out_set.begin(), out_set.end(), print);
}
