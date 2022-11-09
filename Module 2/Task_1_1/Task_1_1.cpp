// Task_1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

//int* create_int_array(unsigned size = 0) {
//    int* arr = new int [size];
//    return arr;
//}

unsigned arr1_size = 0, arr2_size = 0;
std::string arr_str;

int main()
{
    setlocale(LC_ALL, "Russian");   
    std::ifstream fin("in.txt");
    if (fin.is_open()) {
        fin >> arr1_size;     
        int* arr1 = new int[arr1_size];
        for (int iter = 0; iter < arr1_size; ++iter) {
            fin >> arr1[iter];
            std::cout << arr1[iter] << " ";
        }
        std::cout << "\n";
        fin >> arr2_size;
        int* arr2 = new int[arr2_size];
        for (int iter = 0; iter < arr2_size; ++iter) {
            fin >> arr2[iter];
            std::cout << arr2[iter] << " ";
        }
        std::ofstream fout("out.txt");
        if (fout.is_open()) {
            fout << arr2_size << "\n";
            fout << arr2[arr2_size - 1] << " ";
            for (unsigned iter = 0; iter < arr2_size - 1; ++iter) {
                fout << arr2[iter] << " ";
            }
            fout << "\n";
            fout << arr1_size << "\n";
            for (unsigned iter = 1; iter < arr1_size; ++iter) {
                fout << arr1[iter] << " ";
            }
            fout << arr1[0];
            fout.close();
        }
    }
    else {
        std::cout << "Не получилось открыть файл!";
    }
}
