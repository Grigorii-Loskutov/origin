﻿// Task_8_1.cpp : Задача 2. Топологическая сортировка орграфа
// https://github.com/netology-code/algocpp-homeworks/tree/main/8/02

#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

void dfs(int** arr, bool* arr_visited, int virtex, int arr_size, int* order, int* call_count) {
	arr_visited[virtex] = true;
	std::cout << virtex + 1 << " ";

	for (int iter = 0; iter < arr_size; iter++) {
		if ((arr[virtex][iter] == 1) && (arr_visited[iter] == false)) {
			dfs(arr, arr_visited, iter, arr_size, order, call_count);
		}
	}
	order[*call_count] = virtex + 1;
	(*call_count)--;
}

unsigned arr_size = 0;
std::string arr_str;

void main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream fin("input.txt");
	std::getline(fin, arr_str);
	std::stringstream stream1(arr_str);
	stream1 >> arr_size;
	int** arr = new int* [arr_size];
	int* order = new int [arr_size];
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

	int call_count = arr_size - 1;
	bool* arr_visited = new bool[arr_size]();
	for (int iter = 0; iter < arr_size; iter++) {
		if (arr_visited[iter] == false) {
			dfs(arr, arr_visited, iter, arr_size, order, &call_count);
		}
		else {
			nullptr;
		}
	}
	std::cout << "\nТопологический порядок вершин: ";
	for (int iter = 0; iter < arr_size; iter++) {
		std::cout << order[iter] << " ";
	}
}
