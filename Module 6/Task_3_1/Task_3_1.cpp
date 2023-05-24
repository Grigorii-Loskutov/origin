// Task_3_1.cpp : «Сортировка выбором»
//

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

//std::vector<int>::iterator findMin(std::promise<std::vector<int>>& unsortVector) {
//
//	
//	std::vector<int>::iterator minimum = std::min_element(unsortVector.begin(), unsortVector.end());
//
//	// Устанавливаем результат в объект promise
//	unsortVector.set_value(result);
//}


int main(int argc, char** argv)
{

	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//создадим вектор случайных значений
	std::vector<int> unsortVector = randomNumber(100, 20);
	std::cout << "Unsorted random vector: "; print(unsortVector);
	/*std::vector<int>::iterator minimum = std::min_element(unsortVector.begin(), unsortVector.end());
	std::cout << *minimum;*/
	std::vector<int> sortVector{};
	while (unsortVector.size() > 0) {
		std::vector<int>::iterator minimum = std::min_element(unsortVector.begin(), unsortVector.end());
		sortVector.push_back(*minimum);
		unsortVector.erase(minimum);
	}
	std::cout << "Sorted vector: "; print(sortVector);
	return 0;
}
