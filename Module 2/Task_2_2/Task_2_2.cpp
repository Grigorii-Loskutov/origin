// Task_2_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

struct bank_account
{
    unsigned number = 0;
    std::string first_name;
    double balance = 0;
};
void balance_changer(bank_account* person, unsigned new_balance) {
    person->balance = new_balance;
}
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bank_account person1;
    unsigned new_balance;
    std::cout << "Введите новый номер счета: "; std::cin >> person1.number;
    std::cout << "Введите имя владельца: "; std::cin >> person1.first_name;
    std::cout << "Введите баланс: "; std::cin >> person1.balance;
    std::cout << "Введите новый баланс: "; std::cin >> new_balance;
    balance_changer(&person1, new_balance);
    std::cout << "Ваш счёт: " << person1.first_name << ", " << person1.number << ", " << person1.balance;
}

