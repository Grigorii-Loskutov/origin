// Task_5_1.cpp : Задача 1. Возведение в квадрат
// https://github.com/netology-code/cppl-homeworks/tree/main/05/01

#include <iostream>
#include <windows.h>
#include <vector>

template <class T>
void square(T num) {
	std::cout << "[IN]: " << num << "\n";
	std::cout << "[OUT]: " << num * num << "\n";
}


template <class T>
void square(const std::vector<T> &vec) {
	auto it = vec.begin();
	std::cout << "[IN]: ";
	while (it != vec.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n";
	it = vec.begin();
	std::cout << "[OUT]: ";
	while (it != vec.end()) {
		std::cout << (*it) * (*it) << " ";
		++it;
	}
	std::cout << "\n";
}



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int int_num = 4;
	double double_num = 12.2;

	std::vector<int> vec { 1, 10, 7,-9, 4 };

	square(int_num);
	square(vec);
}

