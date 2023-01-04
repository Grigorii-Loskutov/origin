
#include <iostream>
#include <string>
#include <windows.h>

#include "RaceControl.h"
//#include "Vehicle.h"
//#include "Camel.h"
//#include "FastCamel.h"
//#include "Centaur.h"
//#include "Boots.h"
//#include "Carpet.h"
//#include "Eagle.h"
//#include "Broom.h"

enum class states {
	race_create,
	race_type,
	start_state,
	vechicle_registration,
	results
};

bool exit_program = false;
unsigned choise = 0;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	states screen = states::race_create;
	RaceControl Race;
	unsigned range = 0;
	std::string reg_result;
	while (exit_program == false)
	{
		switch (screen)
		{
		case states::race_create:
			Race = RaceControl::RaceControl();
			screen = states::race_type;
		case states::race_type:
			choise = 0;
			std::system("cls");
			std::cout << "Добро пожаловать в гоночный симулятор!\n";
			std::cout << "1. Гонка для наземного транспорта\n";
			std::cout << "2. Гонка для воздушного транспорта\n";
			std::cout << "3. Гонка для наземного и воздушного транспорта\n";
			std::cout << "Выберите действие: ";
			std::cin >> choise;
			Race.set_race_type(choise);
			std::cout << "Укажите длину дистанции (должна быть положительной): ";
			std::cin >> range;
			Race.set_range(range);
			screen = states::start_state;
			break;
		case states::start_state:
			choise = 0;
			std::system("cls");
			std::cout << Race.get_race_status() << "\n";
			std::cout << "1. Зарегистрировать транспорт\n";
			std::cout << "2. Начать гонку\n";
			std::cin >> choise;
			if (choise == 1) {
				screen = states::vechicle_registration;
			}
			else if (choise == 2) {
				if (Race.get_vehicle_summ() < 2) {
					screen = states::start_state;
				}
				else {
					screen = states::results;
				}
			}
			break;
		case states::vechicle_registration:
			choise = 0;
			std::system("cls");
			std::cout << reg_result << "\n";
			std::cout << Race.get_race_status() << "\n";
			std::cout << "Регистрация транспорта\n";
			std::cout << "1. Ботинки-вездеходы\n";
			std::cout << "2. Метла\n";
			std::cout << "3. Верблюд\n";
			std::cout << "4. Кентавр\n";
			std::cout << "5. Орёл\n";
			std::cout << "6. Верблюд-быстроход\n";
			std::cout << "7. Ковёр-самолёт\n";
			std::cout << "0. Закончить регистрацию\n";
			std::cin >> choise;
			if (choise == 0) {
				screen = states::start_state;
			}
			else {
				reg_result = Race.vechicle_registration(choise);
			}
			break;
		case states::results:
			choise = 0;
			std::system("cls");
			std::cout << "Результаты гонки:\n";
			std::cout << Race.get_results() << "\n";
			std::cout << "1. Провести ещё одну гонку\n";
			std::cout << "2. Выйти\n";
			std::cin >> choise;
			if (choise == 1) {
				screen = states::race_create;
			}
			else if (choise == 2) {
				exit_program = true;
			}
			break;
		default:
			break;
		}
	}

}