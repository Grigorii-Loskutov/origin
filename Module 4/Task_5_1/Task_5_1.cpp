// Task_5_1.cpp : Задача 1. Возведение в квадрат
// https://github.com/netology-code/cppl-homeworks/tree/main/05/01

#include <iostream>
#include <windows.h>
#include <vector>

template <class T>
void square(T num) {
	num = num * num;
}


template <class T>
void square(std::vector<T> &vec) {
	auto it = vec.begin();
	while (it != vec.end()) {
		*it = (*it) * (*it);
		++it;
	}
}

template <class T>
void print(const std::vector<T>& vec) {
	auto it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << " ";
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
	std::cout << "[IN]: " << int_num << "\n";
	square(int_num);
	std::cout << "[OUT]: " << int_num << "\n";

	std::cout << "[IN]: ";
	print(vec);
	square(vec);
	std::cout << "[OUT]";
	print(vec);
}

