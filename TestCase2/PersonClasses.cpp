#include <iostream>
#include <algorithm>
#include "PersonClasses.h"

// Конструкторы структуры для представления человека
Person::Person(const std::string& _lastName, const std::string& _firstName, int _age, int _job_id, int _position_id) : lastName{ _lastName }, firstName{ _firstName }, age{ _age }, job_id{ _job_id }, position_id{ _position_id } {}
Person::Person() {
	lastName = "lastName";
	firstName = "firstName";
	age = 0;
	job_id = 0;
	position_id = 0;
}

// Конструкторы структуры для представления работы
Job::Job(const std::string& _name, int _id) : name{ _name }, id{ _id } {}
Job::Job() {
	name = "jobName";
	id = 0;
}

// Конструкторы структуры для представления должности
Position::Position(const std::string& _name, int _id) : name{ _name }, id{ _id } {}
Position::Position() {
	name = "positionName";
	id = 0;
}

// Метод класса PersonsList для добавления сотрудника
void PersonsList::addPerson(const Person& person) {
	persons.push_back(person);
}

// Метод класса PersonsList для добавления вакансии
void PersonsList::addPosition(const Position& position) {
	positionsMap[position.id].name = position.name;
}

// Метод класса PersonsList для добавления работы
void PersonsList::addJob(const Job& job) {
	jobsMap[job.id].name = job.name;
}

// Функция-компаратор для сортировки по имени (фамилии, затем имени)
bool compareByName(const Person& person1, const Person& person2) {
	if (person1.lastName == person2.lastName) {
		return person1.firstName < person2.firstName;
	}
	return person1.lastName < person2.lastName;
}

// Функция-компаратор для сортировки по возрасту
bool compareByAge(const Person& person1, const Person& person2) {
	return person1.age < person2.age;
}

// Метод класса PersonsList для вывода списка людей
void PersonsList::print() {
	std::cout << "\n";
	for (const auto& iter : persons) {
		std::string currentJob = jobsMap[iter.job_id].name;
		std::string currentPosition = positionsMap[iter.position_id].name;
		std::cout << iter.firstName << "\t" << iter.lastName << "\t" << iter.age << "\t" << currentJob << "\t" << currentPosition << "\n";
	}
}

// Метод класса PersonsList для сортировки по имени
void PersonsList::sortByName() {
	stable_sort(persons.begin(), persons.end(), compareByName);
}

// Метод класса PersonsList для сортировки по возрасту
void PersonsList::sortByAge() {
	stable_sort(persons.begin(), persons.end(), compareByAge);
}

// Метод класса PersonsList для сортировки по работе
void PersonsList::sortByJob() {
	stable_sort(persons.begin(), persons.end(), [this](const Person& p1, const Person& p2) {
		return jobsMap.at(p1.job_id).name < jobsMap.at(p2.job_id).name; });
}




