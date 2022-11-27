// TasK_6_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>
#include "Counter.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::string answer;
    std::cin >> answer;
    int init_count_value = 0;
    if (answer == "да" or answer == "Да" or answer == "ДА" or answer == "дА") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> init_count_value;
    }
    Counter ticker(init_count_value);
    char key = 'x';
    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> key;
        ticker.adder(key);
        if (key == '=') {
            std::cout << ticker.adder(key) << "\n";
        }
    } while (key != 'x');
    std::cout << "До свидания!\n";
}

