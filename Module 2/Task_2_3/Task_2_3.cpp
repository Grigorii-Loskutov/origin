// Task_2_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

struct address {
    std::string country;
    std::string city;
    std::string street;
    unsigned house;
    unsigned apartament;
    unsigned index;
};

void struct_print(address* addr_exemplar) {
    std::cout << "Страна: " << addr_exemplar->country << "\n";
    std::cout << "Город: " << addr_exemplar->city << "\n";
    std::cout << "Улица: " << addr_exemplar->street << "\n";
    std::cout << "Дом: " << addr_exemplar->house << "\n";
    std::cout << "Квартира: " << addr_exemplar->apartament << "\n";
    std::cout << "Индекс: " << addr_exemplar->index << "\n";
}


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    address addr1 = { "Россия","Таганрог","Петровская",100,1,347900 };
    address addr2 = { "Россия","Лермонтов","Волкова",14,3,357340 };
    struct_print(&addr1);
    std::cout << "\n";
    struct_print(&addr2);
}
