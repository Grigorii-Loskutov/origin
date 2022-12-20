// GreetClient.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "Greet.h"
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Greet::Greet example;
    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    name = example.greet(name) + "!";
    std::cout << name;
}