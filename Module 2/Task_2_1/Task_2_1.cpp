#include <iostream>

enum class months {
    Out, January, February, March, April, May, June, July, August,
    September, October, November, December
};

int main()
{
	months month = months::January;
	unsigned month_number = 0;
	do {
		setlocale(LC_ALL, "Russian");
		std::cout << "Введите номер месяца: ";
		std::cin >> month_number;
		month = static_cast<months>(month_number);
		switch (month)
		{
		case months::January:
			std::cout << "Январь\n";
			break;
		case months::February:
			std::cout << "Февраль\n";
			break;
		case months::March:
			std::cout << "Март\n";
			break;
		case months::April:
			std::cout << "Апрель\n";
			break;
		case months::May:
			std::cout << "Май\n";
			break;
		case months::June:
			std::cout << "Июнь\n";
			break;
		case months::July:
			std::cout << "Июль\n";
			break;
		case months::August:
			std::cout << "Август\n";
			break;
		case months::September:
			std::cout << "Сентябрь\n";
			break;
		case months::October:
			std::cout << "Октябрь\n";
			break;
		case months::November:
			std::cout << "Ноябрь\n";
			break;
		case months::December:
			std::cout << "Декабрь\n";
			break;
		case months::Out:
			std::cout << "До свидания\n";
			break;
		default:
			std::cout << "Неправильный номер!\n";
			break;
		}
		
	} while (month_number != 0);
}

