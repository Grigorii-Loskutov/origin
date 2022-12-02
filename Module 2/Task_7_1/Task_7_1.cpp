// Task_7_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>

#define MODE 1

#ifndef MODE
#error define MODE
#endif

#if MODE == 1
int add(int* n1, int* n2) {
	return *n1 + *n2;
	}
#endif

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#if MODE == 1
	int n1 = 0, n2 = 0;
	std::cout << "Работаю в боевом режиме\n";
	std::cout << "Введите число 1: "; std::cin >> n1;
	std::cout << "Введите число 2: "; std::cin >> n2;
	std::cout << "Результат сложения: " << add(&n1, &n2);
#elif MODE == 0
	std::cout << "Работаю в режиме тренировки";
#else
	std::cout << "Неизвестный режим.Завершение работы";
#endif

}

