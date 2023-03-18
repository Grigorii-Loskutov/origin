// Task_7_2.cpp : https://github.com/netology-code/cppl-homeworks/tree/main/08/02
// Задача 2. Печать контейнера

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <windows.h>

template <typename T>
void print_container(T container)
{
	auto iter = container.begin();
	while (iter != container.end()) {
		std::cout << *iter << " ";
		iter++;
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	std::list<std::string> test_list = { "one", "two", "three", "four" };
	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_set);
	std::cout << "\n";
	print_container(test_list);
	std::cout << "\n";
	print_container(test_vector);
	std::cout << "\n";
}
