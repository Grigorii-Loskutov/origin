#pragma once

#include <string>
#include <vector>
#include <map>
#include <algorithm>

// Структура для представления человека
struct Person {
    Person();  // Конструктор по умолчанию
    Person(const std::string& _lastName, const std::string& _firstName, int _age, int _job_id, int _position_id);

    std::string lastName;   // Фамилия
    std::string firstName;  // Имя
    int age;                // Возраст
    int job_id;             // Идентификатор работы
    int position_id;        // Идентификатор должности
};

// Структура для представления работы
struct Job {
    Job();  // Конструктор по умолчанию
    Job(const std::string& _name, int _id);

    std::string name;  // Название работы
    int id;            // Идентификатор работы
};

// Структура для представления должности
struct Position {
    Position();  // Конструктор по умолчанию
    Position(const std::string& _name, int _id);

    std::string name;  // Название должности
    int id;            // Идентификатор должности
};

// Класс для хранения списка людей и управления ими
class PersonsList {
public:
    // Добавление человека, работы и должности в списки
    void addPerson(const Person& person);
    void addPosition(const Position& position);
    void addJob(const Job& job);

    // Вывод списка людей
    void print();

    // Методы сортировки
    void sortByName();  // Сортировка по имени
    void sortByAge();   // Сортировка по возрасту
    void sortByJob();   // Сортировка по работе

private:
    std::vector<Person> persons;        // Список людей
    std::map<int, Job> jobsMap;         // Отображение id работы -> работа
    std::map<int, Position> positionsMap; // Отображение id должности -> должность
};