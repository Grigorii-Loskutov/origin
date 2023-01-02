
#include <iostream>
#include <string>
#include <windows.h>

#include "Vehicle.h"
#include "Camel.h"
#include "FastCamel.h"
#include "Centaur.h"
#include "Boots.h"
#include "Carpet.h"
#include "Eagle.h"
#include "Broom.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Camel TC1 = Camel::Camel();
	std::cout << TC1.get_name() << ": " << TC1.get_time(4500);
	std::cout << "\n";
	FastCamel TC2 = FastCamel::FastCamel();
	std::cout << TC2.get_name() << ": " << TC2.get_time(4500);
	std::cout << "\n";
	Centaur TC3 = Centaur::Centaur();
	std::cout << TC3.get_name() << ": " << TC3.get_time(4500);
	std::cout << "\n";
	Boots TC4 = Boots::Boots();
	std::cout << TC4.get_name() << ": " << TC4.get_time(4500);
	std::cout << "\n";
	Carpet TC5 = Carpet::Carpet();
	std::cout << TC5.get_name() << ": " << TC5.get_time(4500);
	std::cout << "\n";
	Eagle TC6 = Eagle::Eagle();
	std::cout << TC6.get_name() << ": " << TC6.get_time(4500);
	std::cout << "\n";
	Broom TC7 = Broom::Broom();
	std::cout << TC7.get_name() << ": " << TC7.get_time(4500);
	
}