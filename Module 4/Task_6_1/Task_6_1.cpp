// Task_6_1.cpp : Задача 1. Частота символов
// https://github.com/netology-code/cppl-homeworks/tree/main/07/01

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <windows.h>


int main()
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string str = "Hello world!!";
	std::map<char, int> keyAndMap;
	for (const auto iter : str) {
		keyAndMap[iter] += 1;
	}
	for (const auto& n : keyAndMap) {
		std::cout << n.first << ": " << n.second << "\n";
	}
	std::cout << "____________________\n";
	//Честно подсмотренно на stackoverflow
	std::set<std::pair<int, char>> s;
	for (auto const& kv : keyAndMap) {
		s.emplace(kv.second, kv.first);
	}

	auto print = [](auto& n) { std::cout << n.first << ": " << n.second << "\n"; };
	std::for_each(s.rbegin(), s.rend(), print);

	/*for (auto const& vk : s) {
		std::cout << vk.first << ": " << vk.second << "\n";
	}*/
	

	
}
