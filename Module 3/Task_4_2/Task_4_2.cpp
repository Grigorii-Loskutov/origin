// Task_4_2.cpp : Задача 2. Добавление в изменяемый динамический массив
// https://github.com/netology-code/algocpp-homeworks/tree/main/4/02

#include <iostream>
#include <windows.h>

void print_dynamic_array(int* arr, int* logical_size, int* actual_size) {
	std::cout << "Динамический массив: ";
	for (unsigned iter = 0; iter < *logical_size; iter++) {
		std::cout << arr[iter] << " ";
	}
	for (unsigned iter = *logical_size; iter < *actual_size; iter++) {
		std::cout << "_" << " ";
	}
	std::cout << "\n";
}

int* append_to_dynamic_array(int* arr, int* logical_size, int* actual_size, int new_element) {
	if (*logical_size + 1 <= *actual_size) {
		arr[*logical_size] = new_element;
		*logical_size = *logical_size + 1;
		return arr;
	}
	else {
		*actual_size *= 2;
		int* arr_new = new int[*actual_size];
		for (unsigned iter = 0; iter < *logical_size; iter++) {
			arr_new[iter] = arr[iter];
		}
		delete[] arr;
		arr_new[*logical_size] = new_element;
		*logical_size = *logical_size + 1;
		return arr_new;
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
		print_dynamic_array(arr, &logical_size, &actual_size);
		do {
			int new_element = 0;
			std::cout << "Введите элемент для добавления: "; std::cin >> new_element;
			if (new_element == 0) break;
			arr = append_to_dynamic_array(arr, &logical_size, &actual_size, new_element);
			print_dynamic_array(arr, &logical_size, &actual_size);
		} while (1);
	}
	else {
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!\n";
	}
}