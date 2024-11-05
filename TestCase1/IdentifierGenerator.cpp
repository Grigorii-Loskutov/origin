#include "IdentifierGenerator.h"

// Основной метод генерации следующего идентификатора
std::string IdentifierGenerator::GenerateNextIdentifier(const std::string& identifier) {
    std::vector<std::string> parts = SplitIdentifier(identifier);
    IncrementIdentifier(parts);
    return JoinIdentifier(parts);
}

// Метод для разбиения идентификатора на группы
std::vector<std::string> IdentifierGenerator::SplitIdentifier(const std::string& identifier) {
    std::vector<std::string> parts;
    for (size_t i = 0; i < identifier.size(); i += 2) {
        parts.push_back(identifier.substr(i, 2));
    }
    return parts;
}

// Метод для соединения групп обратно в строку
std::string IdentifierGenerator::JoinIdentifier(const std::vector<std::string>& parts) {
    std::string result;
    for (const auto& part : parts) {
        result += part;
    }
    return result;
}

// Метод для инкремента идентификатора
void IdentifierGenerator::IncrementIdentifier(std::vector<std::string>& parts) {
    int position = parts.size() - 1;
    bool carry = true;

    // Обработка инкремента с конца к началу
    while (carry && position >= 0) {
        std::string& part = parts[position];
        carry = IncrementPart(part);

        // Если дошли до начала и есть перенос, добавляем новую группу
        if (carry && position == 0 && parts.size() < 10) {
            parts.insert(parts.begin(), "A1");
            carry = false;
        }
        --position;
    }
}

// Метод для инкремента одной группы
bool IdentifierGenerator::IncrementPart(std::string& part) {
    int letter_pos = allowed_letters.find(part[0]);
    int digit_pos = allowed_digits.find(part[1]);

    // Переход к следующей цифре
    if (digit_pos + 1 < allowed_digits.size()) {
        part[1] = allowed_digits[digit_pos + 1];
        return false; // нет переноса
    }
    else {
        part[1] = allowed_digits[0]; // сброс цифры и перенос

        // Переход к следующей букве
        if (letter_pos + 1 < allowed_letters.size()) {
            part[0] = allowed_letters[letter_pos + 1];
            return false; // нет переноса
        }
        else {
            part[0] = allowed_letters[0]; // сброс буквы
            return true; // перенос
        }
    }
}