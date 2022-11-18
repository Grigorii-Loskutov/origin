// Task_3_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

class Calculator {
private:
    double num1 = 0;
    double num2 = 0;
public:
    double add() {
        return num1 + num2;
    }
    double multiply() {
        return num1 * num2;
    }
    double subtract_1_2() {
        return num1 - num2;
    }
    double subtract_2_1() {
        return num2 - num1;
    }
    double divide_1_2() {
        return num1 / num2;
    }
    double divide_2_1() {
        return num2 / num1;
    }
public:
    bool set_num1(double num1) {
        if (0 != num1) {
            this->num1 = num1;
            return true;
        }
        else {
            return false;
        }
    }
    bool set_num2(double num2) {
        if (0 != num2) {
            this->num2 = num2;
            return true;
        }
        else {
            return false;
        }
        
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double num1 = 0, num2 = 0;
    while (1) {
        std::cout << "Введите num1: "; std::cin >> num1;
        std::cout << "Введите num2: "; std::cin >> num2;
        Calculator example;
        if ((example.set_num1(num1) == false) or (example.set_num2(num2) == false)) {
            std::cout << "Невернный ввод!\n";
        }
        else {
            std::cout << "num1 + num2 = " << example.add() << "\n";
            std::cout << "num1 - num2 = " << example.subtract_1_2() << "\n";
            std::cout << "num2 - num1 = " << example.subtract_2_1() << "\n";
            std::cout << "num1 * num2 = " << example.multiply() << "\n";
            std::cout << "num1 / num2 = " << example.divide_1_2() << "\n";
            std::cout << "num2 / num1 = " << example.divide_2_1() << "\n";
        }
    }
}
