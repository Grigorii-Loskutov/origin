// Task_4_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <algorithm>

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
	address(std::string city, std::string street, int house, int apartment) {
		this->city = city;
		this->street = street;
		this->house = house;
		this->apartament = apartment;
	}
	/*void address_add(std::string city, std::string street, int house, int apartment) {
		this->city = city;
		this->street = street;
		this->house = house;
		this->apartament = apartment;
	}*/
	std::string get_city() {
		return city;
	}
};

void sort_addr(address* addresses, int addresses_n) {
	bool swapped = false;
	do {
		swapped = false;
		for (int iter = 1; iter < addresses_n; iter++)
		{
			if (addresses[iter - 1].get_city() > addresses[iter].get_city())
			{
				address temp = addresses[iter - 1];
				addresses[iter - 1] = addresses[iter];
				addresses[iter] = temp;
				swapped = true;
			}
		}
	} while (swapped);
}

void main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream fin("in.txt");
	if (fin.is_open()) {
		unsigned address_quantity;
		fin >> address_quantity;
		address* address_from_file = new address[address_quantity];
		for (unsigned address_iter = 0; address_iter < address_quantity; address_iter++) {
			std::string temp_city; fin >> temp_city;
			std::string temp_street; fin >> temp_street;
			int temp_house; fin >> temp_house;
			int temp_apartment; fin >> temp_apartment;
			address_from_file[address_iter] = address(temp_city, temp_street, temp_house, temp_apartment);
		}
		sort_addr(address_from_file, address_quantity);
		std::ofstream fout("out.txt");
		fout << address_quantity; fout << "\n";
		for (unsigned address_iter = 0; address_iter < address_quantity; address_iter++) {
			fout << address_from_file[address_iter].get_output_address();
		}
		fin.close();
		fout.close();
		delete[] address_from_file;
	}
	else {
		std::cout << "Не получилось открыть файл!";
	}


}