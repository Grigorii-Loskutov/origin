#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "RaceControl.h"
#include "Vehicle.h"
#include "Camel.h"
#include "FastCamel.h"
#include "Centaur.h"
#include "Boots.h"
#include "Carpet.h"
#include "Eagle.h"
#include "Broom.h"

RaceControl::RaceControl() {
	this->race_type = race_type::mix;
	this->range = 0;
	this->Camel_created = false;
	this->FastCamel_created = false;
	this->Centaur_created = false;
	this->Boots_created = false;
	this->Carpet_created = false;
	this->Eagle_created = false;
	this->Broom_created = false;
	this->Broom_veh = Broom::Broom();
	this->Camel_veh = Camel::Camel();
	this->Boots_veh = Boots::Boots();
	this->FastCamel_veh = FastCamel::FastCamel();
	this->Eagle_veh = Eagle::Eagle();
	this->Centaur_veh = Centaur::Centaur();
	this->Carpet_veh = Carpet::Carpet();
	this->vehicle_summ = 0;
}
void RaceControl::set_race_type(unsigned number) {
	switch (number) {
	case 1:
		race_type = race_type::ground;
		break;
	case 2:
		race_type = race_type::air;
		break;
	case 3:
		race_type = race_type::mix;
		break;
	default:
		race_type = race_type::mix;
	}
}
void RaceControl::set_range(double range) {
	this->range = range;
}
std::string RaceControl::vechicle_registration(unsigned number) {
	switch (number) {
	case 1:
		if (race_type == race_type::mix or race_type == race_type::ground)
		{
			if (Boots_created == false) {
				Boots_created = true; vehicle_summ++;
				return "Ботнки-вездеходы успешно зарегистрированы!\n";
			}
			else {
				return "Ботнки-вездеходы уже были зарегистрированы!\n";
			}
		}
		else {
			return "Ботинки-вездеходы невозможно зарегистрировать в воздушной гонке";
		}
		break;
	case 2:
		if (race_type == race_type::mix or race_type == race_type::air)
		{
			if (Broom_created == false) {
				Broom_created = true; vehicle_summ++;
				return "Метла успешно зарегистрирована!\n";
			}
			else {
				return "Метла уже была зарегистрирована!\n";
			}
		}
		else
		{
			return "Метлу невозможно зарегистрировать в наземной гонке!\n";
		}

		break;
	case 3:
		if (race_type == race_type::mix or race_type == race_type::ground)
		{
			if (Camel_created == false) {
				Camel_created = true; vehicle_summ++;
				return "Верблюд успешно зарегистрирован!\n";
			}
			else {
				return "Верблюд уже был зарегистрирован!\n";
			}
		}
		else {
			return "Верблюда невозможно зарегистрировать в воздушной гонке";
		}
		break;
	case 4:
		if (race_type == race_type::mix or race_type == race_type::ground) {
			if (Centaur_created == false) {
				Centaur_created = true; vehicle_summ++;
				return "Кентавр успешно зарегистрирован!\n";
			}
			else {
				return "Кентавр уже был зарегистрирован!\n";
			}
		}
		else {
			return "Кентавра невозможно зарегистрировать в воздушной гонке";
		}
	case 5:
		if (race_type == race_type::mix or race_type == race_type::air)
		{
			if (Eagle_created == false) {
				Eagle_created = true; vehicle_summ++;
				return "Орёл успешно зарегистрирован!\n";
			}
			else {
				return "Орёл уже был зарегистрирован!\n";
			}
		}
		else {
			return "Орла невозможно зарегистрировать в наземной гонке!\n";
		}
	case 6:
		if (race_type == race_type::mix or race_type == race_type::ground)
		{
			if (FastCamel_created == false) {
				FastCamel_created = true; vehicle_summ++;
				return "Верблюд-быстроход успешно зарегистрирован!\n";
			}
			else {
				return "Верблюд-быстроход уже был зарегистрирован!\n";
			}
		}
		else {
			return "Верблюд-быстроход не может быть зарегистрирован в воздушной гонке";
		}
	case 7:
		if (race_type == race_type::mix or race_type == race_type::air)
		{
			if (Carpet_created == false) {
				Carpet_created = true; vehicle_summ++;
				return "Ковёр-самолёт успешно зарегистрирован!\n";
			}
			else {
				return "Ковёр-самолёт уже был зарегистрирован!\n";
			}
		}
		else {
			return "Ковер-самолёт не может быть зарегистрирован в воздушной гонке";
		}
		break;
	default:
		return "Некорректный выбор";
	}
}
std::string RaceControl::get_race_status() {
	std::stringstream ss;
	if (vehicle_summ < 2) {
		ss << "В гонке должно быть зарегистрированно не менее двух учатников\n";
	}
	switch (race_type)
	{
	case race_type::ground:
		ss << "Гонка для наземного транспорта. ";
		break;
	case race_type::air:
		ss << "Гонка для воздушного транспорта. ";
		break;
	case race_type::mix:
		ss << "Гонка для наземного и воздушного транспорта. ";
		break;
	default:
		ss << "Гонка неопределена! ";
		break;
	}
	ss << "Расстояние: " << range << "\n";
	ss << "Зарегистрированные транспортные средства: ";
	if (Camel_created == true) {
		ss << Camel_veh.get_name() << " ";
	}
	if (Broom_created == true) {
		ss << Broom_veh.get_name() << " ";
	}
	if (Boots_created == true) {
		ss << Boots_veh.get_name() << " ";
	}
	if (FastCamel_created == true) {
		ss << FastCamel_veh.get_name() << " ";
	}
	if (Carpet_created == true) {
		ss << FastCamel_veh.get_name() << " ";
	}
	if (Centaur_created == true) {
		ss << Centaur_veh.get_name() << " ";
	}
	if (Eagle_created == true) {
		ss << Eagle_veh.get_name() << " ";
	}
	ss << "\n";
	return ss.str();
}
std::string RaceControl::get_results() {
	std::stringstream ss;
	Vehicle* vehicle_arr = new Vehicle[vehicle_summ];
	unsigned iter = 0;
	if (Camel_created == true) {
		//ss << Camel_veh.get_name() << ". Результат: " << Camel_veh.get_time(range) << "\n";
		Camel_veh.calc_time(range);
		vehicle_arr[iter] = Camel_veh; iter++;
	}
	if (Broom_created == true) {
		//ss << Broom_veh.get_name() << ". Результат: " << Broom_veh.get_time(range) << "\n";
		Broom_veh.calc_time(range);
		vehicle_arr[iter] = Broom_veh; iter++;
	}
	if (Boots_created == true) {
		//ss << Boots_veh.get_name() << ". Результат: " << Boots_veh.get_time(range) << "\n";
		Boots_veh.calc_time(range);
		vehicle_arr[iter] = Boots_veh; iter++;
	}
	if (FastCamel_created == true) {
		//ss << FastCamel_veh.get_name() << ". Результат: " << FastCamel_veh.get_time(range) << "\n";
		FastCamel_veh.calc_time(range);
		vehicle_arr[iter] = FastCamel_veh; iter++;
	}
	if (Centaur_created == true) {
		//ss << Centaur_veh.get_name() << ". Результат: " << Centaur_veh.get_time(range) << "\n";
		Centaur_veh.calc_time(range);
		vehicle_arr[iter] = Centaur_veh; iter++;
	}
	if (Carpet_created == true) {
		//ss << Carpet_veh.get_name() << ". Результат: " << Carpet_veh.get_time(range) << "\n";
		Carpet_veh.calc_time(range);
		vehicle_arr[iter] = Carpet_veh; iter++;
	}
	if (Eagle_created == true) {
		//ss << Eagle_veh.get_name() << ". Результат: " << Eagle_veh.get_time(range) << "\n";
		Eagle_veh.calc_time(range);
		vehicle_arr[iter] = Eagle_veh;
	}
	ss << "\n";
	sort_veh(vehicle_arr);
	for (unsigned iter = 0; iter < vehicle_summ; iter++) {
		ss << iter + 1 << ". " << vehicle_arr[iter].get_name() << ". Результат: " << vehicle_arr[iter].get_time() << "\n";
	}
	return ss.str();
}
unsigned RaceControl::get_vehicle_summ() {
	return vehicle_summ;
}
void RaceControl::sort_veh(Vehicle* vehicle_arr) {
	bool swapped = false;
	do {
		swapped = false;
		for (unsigned iter = 1; iter < vehicle_summ; iter++)
		{
			if (vehicle_arr[iter - 1].get_time() > vehicle_arr[iter].get_time())
			{
				Vehicle temp = vehicle_arr[iter - 1];
				vehicle_arr[iter - 1] = vehicle_arr[iter];
				vehicle_arr[iter] = temp;
				swapped = true;
			}
		}
	} while (swapped);
}