// Task_5_3.cpp : Задача 3. Счётчик чисел
// https://github.com/netology-code/cppl-homeworks/tree/main/05/03

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

class summ_functor {
private:
	int counter;
	int summ;
public:
	//summ_functor() : counter{0} {}
	summ_functor() : summ{ 0 }, counter{ 0 } {}
	void operator()(std::vector<int> vec) {
		int iter = 0;
		int summ_iter = 0;
		std::for_each(vec.begin(), vec.end(), [&iter, &summ_iter](const int& n) { if (0 == n % 3) { iter++; summ_iter += n; }});
		counter = iter;
		summ = summ_iter;
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
	sf(vec);
	std::cout << "[IN]: ";
	auto print = [](const int& n) { std::cout << " " << n; };
	std::for_each(vec.begin(), vec.end(), print);
	std::cout << "\n";
	std::cout << "[OUT]: get_count() = " << sf.get_count() << "\n";
	std::cout << "[OUT]: get_sum() = " << sf.get_sum() << "\n";
}