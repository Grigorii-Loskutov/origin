// Task_5_1.cpp : Задача 1. Вывод пирамиды на массиве
//https://github.com/netology-code/algocpp-homeworks/tree/main/5/01

#include <iostream>
#include <windows.h>

void print_pyramid(int* arr, int size) {
	std::cout << "Пирамида:\n";
	int layer = 0;
	std::cout << layer << " root " << arr[0] << "\n";
	layer++;
	int parent = 0;
	int left = 0;
	int right = 0;
	int iter = 0;
	int parent_count = 1;
	bool exit = false;
	while (!exit) {
		parent = (iter - 1) / 2;
		left = 2 * iter + 1;
		if (left != size) {
			exit = false;
			std::cout << layer << " " << " left(" << arr[iter] << ") " << arr[left] << "\n";
		}
		else {
			exit = true;
		}
		right = 2 * iter + 2;
		if (right != size) {
			exit = false;
			std::cout << layer << " " << " right(" << arr[iter] << ") " << arr[right] << "\n";
		}
		else {
			exit = true;
		}
		parent_count++;
		if (parent_count%2==0) layer++;
		iter++;
	}
}

void print_array(int* arr, int size) {
	std::cout << "Исходный массив: ";
	for (unsigned iter = 0; iter < size; iter++) {
		std::cout << arr[iter] << " ";
	}
	std::cout << "\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int m1[] = { 1, 3, 6, 5, 9, 8 };
	int size_m1 = sizeof(m1) / sizeof(m1[0]);
	int m2[] = {94, 67, 18, 44, 55, 12, 6, 42};
	int size_m2 = sizeof(m2) / sizeof(m2[0]);
	int m3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
	int size_m3 = sizeof(m3) / sizeof(m3[0]);
	print_array(m1, size_m1);
	print_pyramid(m1, size_m1);
	print_array(m2, size_m2);
	print_pyramid(m2, size_m2);
	print_array(m3, size_m3);
	print_pyramid(m3, size_m3);

}

