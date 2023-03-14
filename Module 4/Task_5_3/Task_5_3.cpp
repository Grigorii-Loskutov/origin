// Task_5_3.cpp : Задача 3. Счётчик чисел
// https://github.com/netology-code/cppl-homeworks/tree/main/05/03

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

class summ_functor {
	int counter;
	int summ;
public:
	summ_functor() : summ{ 0 }, counter{ 0 } {}
	void operator()(int num) {
		if (0 == num % 3) {
			counter++; std::cout << counter;
			summ += num; std::cout << summ;
		}
	}
	int get_sum() {
		return summ;
	}
	int get_count() {
		return counter;
	}
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector<int> vec{ 4, 1, 3, 6, 25, 54 };
	auto sf = summ_functor();
	std::for_each(vec.begin(), vec.end(), sf);
	std::cout << "[IN]: ";
	auto print = [](const int& n) { std::cout << " " << n; };
	std::for_each(vec.begin(), vec.end(), print);
	std::cout << "\n";
	std::cout << "[OUT]: get_count() = " << sf.get_count() << "\n";
	std::cout << "[OUT]: get_sum() = " << sf.get_sum() << "\n";
}