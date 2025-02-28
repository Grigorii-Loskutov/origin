#pragma once

#include <string>
#include <vector>
#include <map>
#include <algorithm>

// ��������� ��� ������������� ��������
struct Person {
    Person();  // ����������� �� ���������
    Person(const std::string& _lastName, const std::string& _firstName, int _age, int _job_id, int _position_id);

    std::string lastName;   // �������
    std::string firstName;  // ���
    int age;                // �������
    int job_id;             // ������������� ������
    int position_id;        // ������������� ���������
};

// ��������� ��� ������������� ������
struct Job {
    Job();  // ����������� �� ���������
    Job(const std::string& _name, int _id);

    std::string name;  // �������� ������
    int id;            // ������������� ������
};

// ��������� ��� ������������� ���������
struct Position {
    Position();  // ����������� �� ���������
    Position(const std::string& _name, int _id);

    std::string name;  // �������� ���������
    int id;            // ������������� ���������
};

// ����� ��� �������� ������ ����� � ���������� ���
class PersonsList {
public:
    // ���������� ��������, ������ � ��������� � ������
    void addPerson(const Person& person);
    void addPosition(const Position& position);
    void addJob(const Job& job);

    // ����� ������ �����
    void print();

    // ������ ����������
    void sortByName();  // ���������� �� �����
    void sortByAge();   // ���������� �� ��������
    void sortByJob();   // ���������� �� ������

private:
    std::vector<Person> persons;        // ������ �����
    std::map<int, Job> jobsMap;         // ����������� id ������ -> ������
    std::map<int, Position> positionsMap; // ����������� id ��������� -> ���������
};