// Task_4_1.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
class address {
private:
	std::string city;
	std::string street;
	int house;
	int apartament;
public:
	std::string get_output_address() {
		std::stringstream ss;
		ss << city << ", " << street << ", " << house << ", " << apartament << "\n";
		return ss.str();
	}
	address() {
		city = "default city";
		street = "default street";
		house = 0;
		apartament = 0;
	}
	address (std::string city, std::string street, int house, int apartment) {
		this->city = city;
		this->street = street;
		this->house = house;
		this->apartament = apartment;
	}
	void address_add_full(std::string city, std::string street, int house, int apartment) {
		this->city = city;
		this->street = street;
		this->house = house;
		this->apartament = apartment;
	}
	void address_add_city(std::string city) {
		this->city = city;
	}
	void address_add_street(std::string street) {
		this->street = street;
	}
	void address_add_house(int house) {	
		this->house = house;
	}
	void address_add_full(int apartment) {
		this->apartament = apartment;
	}
};
void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream fin("in.txt");
	if (fin.is_open()) {
		unsigned address_quantity;
		fin >> address_quantity;
		std::ofstream fout("out.txt");
		fout << address_quantity; fout << "\n";
		address* address_from_file = new address[address_quantity];
		for (unsigned address_iter = 0; address_iter < address_quantity; address_iter++) {
			/*for (unsigned iter = 1; iter <= 4; iter++) {
				std::string temp_city; fin >> temp_city;
				std::string temp_street; fin >> temp_street;
				int temp_house; fin >> temp_house;
				int temp_apartment; fin >> temp_apartment;
			}*/
			std::string temp_city; fin >> temp_city;
			std::string temp_street; fin >> temp_street;
			int temp_house; fin >> temp_house;
			int temp_apartment; fin >> temp_apartment;
			address_from_file[address_iter].address_add_full(temp_city, temp_street, temp_house, temp_apartment);
			fout << address_from_file[address_iter].get_output_address();
		}
		fout.close();
		delete[] address_from_file;
	}
	else {
		std::cout << "Не получилось открыть файл!";
	}

	
}