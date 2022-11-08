// Task_1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

unsigned arr_size = 0;

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string size_of_arr_str, cells_str;
    std::ifstream fin("in.txt");
    if (fin.is_open()) {
        fin >> arr_size;
        std::cout << arr_size;
    }
    else {
        std::cout << "Не получилось открыть файл!";
    }
}
