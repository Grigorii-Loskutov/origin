// Task_6_2.cpp : Задача 2. Настоящая хэш-функция для строки
//https://github.com/netology-code/algocpp-homeworks/tree/main/6/02

#include <iostream>
#include <string.h>
#include <math.h>
#include <windows.h>

int simple_string_hash(char* str, int* length) {
	int summ = 0;
	for (int iter = 0; iter < *length; iter++) {
		summ += str[iter];
	}
	return summ;
}

int real_string_hash(char* str, int* length, int* p, int* n) {
	int summ = 0;
	for (int iter = 0; iter < *length; iter++) {
		summ = summ + std::pow(*p, iter) * str[iter];
	}
	summ = summ % *n;
	return summ;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string str;
	int p = 0;
	int n = 0;
	std::cout << "Введите p: "; std::cin >> p;
	std::cout << "Введите n: "; std::cin >> n;
	do {
		std::cout << "Введите строку: "; std::cin >> str;
		char* char_arr = &str[0];
		int length = str.length();
		std::cout << "Наивный хэш строки " << str << " = " << real_string_hash(char_arr, &length, &p, &n) << "\n";
	} while (str != "exit");
}