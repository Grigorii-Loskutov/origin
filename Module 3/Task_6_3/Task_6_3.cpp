// Task_6_3.cpp : Задача 3. Упрощённый алгоритм Рабина-Карпа
//https://github.com/netology-code/algocpp-homeworks/tree/main/6/03

#include <iostream>
#include <string.h>
#include <math.h>
#include <windows.h>

int simple_string_hash(char* str, int* length) {
	int summ = 0;
	for (int iter = 0; iter < *length; iter++) {
		summ += str[iter];
	}
	return summ;
}

bool full_symbol_seach(char* str1, char* str2, int* length) {
	for (int iter = 0; iter < *length; iter++) {
		if (str1[iter] != str2[iter]) return false;
	}
	return true;
}

int find_substring_light_rabin_karp(char* big_str, int* length_big_str, char* small_str, int* length_small_str) {
	if (*length_small_str > *length_big_str) return -1;
	int small_str_hash = simple_string_hash(small_str, length_small_str);
	int big_str_hash = simple_string_hash(big_str, length_small_str);
	if (small_str_hash == big_str_hash) return 0;
	for (int iter = 1; iter < *length_big_str; iter++) {
		if (small_str_hash == big_str_hash) {
			if(full_symbol_seach(&big_str[iter - 1], &small_str[0], length_small_str)==true) return iter - 1;
		}
		else {
			big_str_hash = big_str_hash - big_str[iter - 1] + big_str[iter - 1 + *length_small_str];
		}
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string big_str;
	std::string small_str;

	int p = 29;
	int n = 1000;
	do {
		std::cout << "Введите строку, в которой будет осуществляться поиск: "; std::cin >> big_str;
		std::cout << "Введите подстроку, которую нужно найти: "; std::cin >> small_str;
		char* char_arr_big_str = &big_str[0];
		char* char_arr_small_str = &small_str[0];
		int length_big_str = big_str.length();
		int length_small_str = small_str.length();
		//std::cout << "Наивный хэш строки " << big_str << " = " << real_string_hash(char_arr_big_str, &length_big_str, &p, &n) << "\n";
		int seach_result = find_substring_light_rabin_karp(char_arr_big_str, &length_big_str, char_arr_small_str, &length_small_str);
		if (seach_result == -1) {
			std::cout << "Подстрока '" << small_str << "' не найдена" << "\n";
		}
		else {
			std::cout << "Подстрока '" << small_str << "' найдена по индексу " << seach_result << "\n";
		}
	} while (small_str != "exit");
}