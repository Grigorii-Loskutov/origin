#include <iostream>
#include <string.h>
#include <windows.h>

void main(void) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string name;
	std::cout << "������� ���: "; std::cin >> name;
	std::cout << "������������, " << name << "!";
}