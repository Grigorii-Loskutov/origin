// Task_6_1.cpp : Задача 1. Наивная хэш-функция для строки
//https://github.com/netology-code/algocpp-homeworks/tree/main/6/01

#include <iostream>
#include <string.h>
#include <windows.h>

int simple_string_hash(char* str, int* length) {
	int summ = 0;
	for (int iter = 0; iter < *length; iter++) {
		summ += str[iter];
	}
	return summ;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string str;
	do {
		std::cout << "Введите строку: "; std::cin >> str;
		char* char_arr = &str[0];
		int length = str.length();
		std::cout << "Наивный хэш строки " << str << " = " << simple_string_hash(char_arr, &length) << "\n";
	} 
	while (str!="exit");
}