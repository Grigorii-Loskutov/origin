#pragma once

#include <string>
#include <vector>
class IdentifierGenerator
{
public:
	// Основной метод генерации следующего идентификатора
	std::string GenerateNextIdentifier(const std::string& identifier);
private:
	// Метод для разбиения идентификатора на группы
	std::vector<std::string> SplitIdentifier(std::string& identifier);

	// Метод для соединения групп обратно в строку
	std::string JoinIdentifier(const std::vector<std::string>& parts);

	// Метод для инкремента идентификатора
	void IncrementIdentifier(std::vector<std::string>& parts);

	// Метод для инкремента одной группы
	bool IncrementPart(std::string& part);

	// Набор допустимых букв и цифр
	const std::string allowed_letters = "ABCEHIKLNOPRSTUWXYZ";
	const std::string allowed_digits = "123456789";
};