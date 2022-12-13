#pragma once
#include <string>
#include <exception>

class FigureCreateclass :public std::exception {
private:
	const char* what() const override { return "Создание фигруы с неподходящими параметрами"; }
public:
	FigureCreateclass(std::string error) : std::domain_error(const char* what_arg);
}