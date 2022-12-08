// Task_8_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <string.h>
#include <exception>

class MyException : public std::exception
{
private:
	std::string err;
public:
	MyException(std::string error) : err(error) {}
	//const char* getError()
	//{
	//	return err.c_str();
	//}
	virtual const char* what() const override
	{
		return err.c_str();
	}
};

const std::string bad_length = "Вы ввели слово запретной длины! До свидания";
int function(std::string str, int forbidden_length) {
	if (str.length() == forbidden_length) throw MyException(bad_length);
	return str.length();
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int fail_length = 0;
	std::cout << "Введите запретную длину: "; std::cin >> fail_length;
	while (1) {
		std::string input_str = "";
		std::cout << "Введите слово: "; std::cin >> input_str;
		try {
			int sample_lengtch = function(input_str, fail_length);
			std::cout << "Длина слова" << "'" << input_str << "'" << "равна " << sample_lengtch << "\n";
			
		}
		catch (const MyException& ex) {
			//std::cout << bad_length;
			std::cerr << ex.what() << "\n";
			break;
		}
	}
}

