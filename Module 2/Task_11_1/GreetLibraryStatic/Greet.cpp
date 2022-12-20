#include <string>
#include "Greet.h"

namespace Greet{
	std::string Greet::greet(std::string name) {
		return "Здравствуйте, " + name;
	}
}
