// Task_3_2.cpp : Реализовать параллельный вариант оператора for_each
//bhttps://github.com/netology-code/map-homeworks/tree/main/03

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
    // Получаем количество потоков процессора
    unsigned int num_threads = std::thread::hardware_concurrency();
    auto block_size = std::distance(begin, end) / num_threads;
    std::vector<std::future<void>> futures;
    for (unsigned int i = 0; i < num_threads; ++i)
    {
        auto block_begin = begin + i * block_size;
        auto block_end = (i == num_threads - 1) ? end : block_begin + block_size;

        // Запускаем задачу для конкретного блока
        futures.push_back(std::async(std::launch::async, [block_begin, block_end, &func]() {
            std::for_each(block_begin, block_end, func);
            }));
    }

    for (auto& future : futures)
    {
        future.get();
    }
}


int main(int argc, char** argv)
{

	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector<int> randomVector = randomNumber(10, 30);
	std::cout << "Random vector: "; print(randomVector);
	auto f_square = [](int& n) { n = n * n; };
	for_each_par(randomVector.begin(), randomVector.end(), f_square);
	std::cout << "Squared vector: "; print(randomVector);
	return 0;
}
