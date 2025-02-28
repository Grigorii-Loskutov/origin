#include <iostream>
#include <algorithm>
#include "PersonClasses.h"

// ������������ ��������� ��� ������������� ��������
Person::Person(const std::string& _lastName, const std::string& _firstName, int _age, int _job_id, int _position_id) : lastName{ _lastName }, firstName{ _firstName }, age{ _age }, job_id{ _job_id }, position_id{ _position_id } {}
Person::Person() {
	lastName = "lastName";
	firstName = "firstName";
	age = 0;
	job_id = 0;
	position_id = 0;
}

// ������������ ��������� ��� ������������� ������
Job::Job(const std::string& _name, int _id) : name{ _name }, id{ _id } {}
Job::Job() {
	name = "jobName";
	id = 0;
}

// ������������ ��������� ��� ������������� ���������
Position::Position(const std::string& _name, int _id) : name{ _name }, id{ _id } {}
Position::Position() {
	name = "positionName";
	id = 0;
}

// ����� ������ PersonsList ��� ���������� ����������
void PersonsList::addPerson(const Person& person) {
	persons.push_back(person);
}

// ����� ������ PersonsList ��� ���������� ��������
void PersonsList::addPosition(const Position& position) {
	positionsMap[position.id].name = position.name;
}

// ����� ������ PersonsList ��� ���������� ������
void PersonsList::addJob(const Job& job) {
	jobsMap[job.id].name = job.name;
}

// �������-���������� ��� ���������� �� ����� (�������, ����� �����)
bool compareByName(const Person& person1, const Person& person2) {
	if (person1.lastName == person2.lastName) {
		return person1.firstName < person2.firstName;
	}
	return person1.lastName < person2.lastName;
}

// �������-���������� ��� ���������� �� ��������
bool compareByAge(const Person& person1, const Person& person2) {
	return person1.age < person2.age;
}

// ����� ������ PersonsList ��� ������ ������ �����
void PersonsList::print() {
	std::cout << "\n";
	for (const auto& iter : persons) {
		std::string currentJob = jobsMap[iter.job_id].name;
		std::string currentPosition = positionsMap[iter.position_id].name;
		std::cout << iter.firstName << "\t" << iter.lastName << "\t" << iter.age << "\t" << currentJob << "\t" << currentPosition << "\n";
	}
}

// ����� ������ PersonsList ��� ���������� �� �����
void PersonsList::sortByName() {
	stable_sort(persons.begin(), persons.end(), compareByName);
}

// ����� ������ PersonsList ��� ���������� �� ��������
void PersonsList::sortByAge() {
	stable_sort(persons.begin(), persons.end(), compareByAge);
}

// ����� ������ PersonsList ��� ���������� �� ������
void PersonsList::sortByJob() {
	stable_sort(persons.begin(), persons.end(), [this](const Person& p1, const Person& p2) {
		return jobsMap.at(p1.job_id).name < jobsMap.at(p2.job_id).name; });
}




