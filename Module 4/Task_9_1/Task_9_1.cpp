// Task_9_1.cpp : Задача 1. Перемещение объектов
// https://github.com/netology-code/cppl-homeworks/tree/main/11/01

#include <iostream>
#include <vector>
#include <windows.h>

template <typename T>
void move_vectors(std::vector<T> &source, std::vector<T> &dest) {
	dest = std::move(source);
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;
	move_vectors<std::string>(one, two);
}