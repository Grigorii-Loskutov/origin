// Task_3_2_v2.cpp : Реализовать параллельный вариант оператора for_each
// https://github.com/netology-code/map-homeworks/tree/main/03

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <thread>
#include <mutex>
#include <future>
#include <random>


//Функция генерации вектора размерностью N случайных чисел равномерного распределения в диапазоне от 0 до range
std::vector<int> randomNumber(int range, int N) {
	std::vector<int> result;
	for (int iter = 0; iter < N; iter++)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(0, range);
		result.push_back(dist(gen));
	}
	return result;
}

//Функция вывода вектора на экран
template <class T>
void print(const std::vector<T>& vec) {
	auto it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n";
}


template<typename Iterator, typename Function>
void for_each_par(Iterator begin, Iterator end, Function&& func)
{
	auto range = std::distance(begin, end);
	if (range > 1) {
		auto L_begin = begin;
		auto L_end = begin + (range / 2);
		auto R_begin = begin + (range / 2) + 1;
		auto R_end = end;
		std::async(std::launch::async, [L_begin, L_end, &func]() {
			for_each_par(L_begin, L_end, func);
			});

		std::async(std::launch::async, [R_begin, R_end, &func]() {
			for_each_par(R_begin, R_end, func);
			});
	}
	else if (range == 1) {
		std::for_each(begin, end, func);
	}
}


int main(int argc, char** argv)
{

	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector<int> randomVector = randomNumber(10, 30);
	std::cout << "Random vector:\t"; print(randomVector);
	auto f_square = [](int& n) { n = n * n; };
	for_each_par(randomVector.begin(), randomVector.end(), f_square);
	std::cout << std::endl;
	std::cout << "Squared vector:\t"; print(randomVector);
	return 0;
}
