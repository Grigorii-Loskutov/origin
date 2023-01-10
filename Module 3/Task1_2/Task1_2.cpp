// Task1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>

unsigned over_func(int *arr, unsigned size, int start_point) {
	unsigned left = 0, right = size - 1, middle = 0;
	if (start_point < arr[left]) {
		return size;
	}
	while (left < right) {
		if ((right-left) % 2 == 0) { middle = (right-left) / 2 + left; }
		else { middle = (right - left + 1) / 2 + left; }
		if ((arr[middle] < start_point) && (arr[middle + 1] > start_point)) {
			return size - middle - 1;
		}
		if ((arr[middle] > start_point) && (arr[middle - 1] < start_point)) {
			return size - middle;
		}
		if ((arr[middle] == start_point) && (arr[middle + 1] > start_point)) {
			return size - middle - 1;
		}
		if (arr[middle] < start_point) {
			left = middle + 1;
		}
		else if (arr[middle] > start_point) {
			right = middle - 1;
		}
	}
	if (arr[left] <= start_point) {
		return size - 1;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int start_point = 0;
	int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72, 100 };
	unsigned arr_size = sizeof(arr) / sizeof(int);
	std::cout << "Заданный массив: ";
	for (unsigned iter = 0; iter < arr_size; iter++) {
		std::cout << arr[iter] << " ";
	}
	std::cout << "\n";
	std::cout << "Введите точку отсчёта: ";
	std::cin >> start_point;
	std::cout << "Количество элементов в массиве больших, чем " << start_point << ": " << over_func(arr, arr_size, start_point);
}
