#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "Vehicle.h"
#include "Camel.h"
#include "FastCamel.h"
#include "Centaur.h"
#include "Boots.h"
#include "Carpet.h"
#include "Eagle.h"
#include "Broom.h"

class RaceControl {
private:
	enum class race_type {
		ground,
		air,
		mix
	};
	race_type race_type;
	double range = 0;
	bool Camel_created = false;
	bool FastCamel_created = false;
	bool Centaur_created = false;
	bool Boots_created = false;
	bool Carpet_created = false;
	bool Eagle_created = false;
	bool Broom_created = false;
	Broom Broom_veh = Broom::Broom();
	Camel Camel_veh = Camel::Camel();
	Boots Boots_veh = Boots::Boots();
	FastCamel FastCamel_veh = FastCamel::FastCamel();
	Eagle Eagle_veh = Eagle::Eagle();
	Centaur Centaur_veh = Centaur::Centaur();
	Carpet Carpet_veh = Carpet::Carpet();
	unsigned vehicle_summ = 0;

public:
	RaceControl();
	void set_race_type(unsigned number);
	void set_range(double range);
	std::string vechicle_registration(unsigned number);
	std::string get_race_status();
	std::string get_results();
	unsigned get_vehicle_summ();
};