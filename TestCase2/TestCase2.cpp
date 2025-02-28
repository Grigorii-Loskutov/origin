// TestCase2.cpp : https://netology.ru/profile/program/job-tz-prog-cpp-2/lessons/433931/lesson_items/2341233
// Кейс «Создание компараторов для алгоритмов сортировки»
#include <iostream>
#include <windows.h>
#include "PersonClasses.h"

// Главная функция программы
int main() {
    setlocale(LC_ALL, "Russia");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Создаются объекты класса Job
    Job j1("City Hall", 1);
    Job j2("Univercity", 2);
    Job j3("Administration", 3);
    Job j4("Hospital", 4);

    // Создаются объекты класса Position
    Position p1("Director", 1);
    Position p2("Manager", 2);
    Position p3("Worker", 3);

    // Создается объект PersonList
    PersonsList MyList;
    // В список добавляются объекты класса Job
    MyList.addJob(j1);
    MyList.addJob(Job("City Hall", 2));
    MyList.addJob(j3);
    MyList.addJob(j4);

    // В список добавляются объекты класса Position
    MyList.addPosition(p1);
    MyList.addPosition(p2);
    MyList.addPosition(p3);

    //Создаются объекты класса Person
    Person m1("Ivanov", "Ivan", 30, 1, 2);
    Person m2("Ivanov", "Anton", 32, 3, 1);
    Person m3("Petrov", "Semen", 30, 4, 2);
    Person m4("Antonov", "Yan", 55, 2, 1);
    Person m5("Sidorov", "Zhenya", 37, 1, 3);
    Person m6("Smirnov", "Misha", 44, 2, 3);

    //Объекты класса Person добавдяются в PersonList 
    MyList.addPerson(m1);
    MyList.addPerson(m2);
    MyList.addPerson(m3);
    MyList.addPerson(m4);
    MyList.addPerson(m5);
    MyList.addPerson(m6);

    //Исходная таблица
    std::cout << "Исходная таблица";
    MyList.print();
    // Сортировка по месту работы
    std::cout << "Сортировка по месту работы";
    MyList.sortByJob();
    MyList.print();
    // Сортировка по имени
    std::cout << "Сортировка по имени";
    MyList.sortByName();
    MyList.print();
    // Сортировка по возрасту
    std::cout << "Сортировка по возрасту";
    MyList.sortByAge();
    MyList.print();

    return 0;
}