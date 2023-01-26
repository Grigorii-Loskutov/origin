// Module 3 Task_4_1.cpp : Задача 1. Вывод изменяемого динамического массива
//https://github.com/netology-code/algocpp-homeworks/tree/main/4/01

#include <iostream>
#include <windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	std::cout << "Динамический массив: ";
	for (unsigned iter = 0; iter < logical_size; iter++) {
		std::cout << arr[iter] << " ";
	}
	for (unsigned iter = logical_size; iter < actual_size; iter++) {
		std::cout << "_" << " ";
	}
}
void main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int logical_size = 0, actual_size = 0;
	std::cout << "Создание динамического массива\n";
	std::cout << "Введите фактичеcкий размер массива: "; std::cin >> actual_size;
	std::cout << "Введите логический размер массива: "; std::cin >> logical_size;
	if (actual_size >= logical_size) {
		int* arr = new int[actual_size];
		for (unsigned iter = 0; iter < logical_size; iter++) {
			std::cout << "Введите arr[" << iter << "]: "; std::cin >> arr[iter];
		}
		print_dynamic_array(arr, logical_size, actual_size);
	}
	else {
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!\n";
	}
}

