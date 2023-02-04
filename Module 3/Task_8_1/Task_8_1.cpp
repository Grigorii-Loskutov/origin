// Task_8_1.cpp : Задача 1. Вывод орграфа на консоль
// https://github.com/netology-code/algocpp-homeworks/tree/main/8/01

#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

unsigned arr_size = 0;
std::string arr_str;
void main(int argc, char** argv);

void main(int argc, char** argv)
{
    std::cout << "Hello World!\n";
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream fin("input.txt");
	std::getline(fin, arr_str);
	std::stringstream stream1(arr_str);
	stream1 >> arr_size;
	int** arr = new int* [arr_size];
	for (int iter_r = 0; iter_r < arr_size; iter_r++) {
		arr[iter_r] = new int[arr_size];
		std::getline(fin, arr_str);
		std::stringstream stream2(arr_str);
		for (int iter_c = 0; iter_c < arr_size; iter_c++) {

			stream2 >> arr[iter_r][iter_c];

			std::cout << arr[iter_r][iter_c] << " ";
		}
		std::cout << "\n";
	}
	for (int iter_c = 0; iter_c < arr_size; iter_c++) {
		int virtex_c = iter_c + 1;
		std::cout << virtex_c << ": ";
		bool rebro = false;
		for (int iter_r = 0; iter_r < arr_size; iter_r++) {
			int virtex_r = iter_r + 1;
			if (arr[iter_c][iter_r] == 1) {
				std::cout << virtex_r << " ";
				rebro = true;
			}
		}
		if (rebro == false) std::cout << "нет";
		std::cout << "\n";
	}
}
