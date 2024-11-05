#include "IdentifierGenerator.h"

// �������� ����� ��������� ���������� ��������������
std::string IdentifierGenerator::GenerateNextIdentifier(const std::string& identifier) {
    std::vector<std::string> parts = SplitIdentifier(identifier);
    IncrementIdentifier(parts);
    return JoinIdentifier(parts);
}

// ����� ��� ��������� �������������� �� ������
std::vector<std::string> IdentifierGenerator::SplitIdentifier(const std::string& identifier) {
    std::vector<std::string> parts;
    for (size_t i = 0; i < identifier.size(); i += 2) {
        parts.push_back(identifier.substr(i, 2));
    }
    return parts;
}

// ����� ��� ���������� ����� ������� � ������
std::string IdentifierGenerator::JoinIdentifier(const std::vector<std::string>& parts) {
    std::string result;
    for (const auto& part : parts) {
        result += part;
    }
    return result;
}

// ����� ��� ���������� ��������������
void IdentifierGenerator::IncrementIdentifier(std::vector<std::string>& parts) {
    int position = parts.size() - 1;
    bool carry = true;

    // ��������� ���������� � ����� � ������
    while (carry && position >= 0) {
        std::string& part = parts[position];
        carry = IncrementPart(part);

        // ���� ����� �� ������ � ���� �������, ��������� ����� ������
        if (carry && position == 0 && parts.size() < 10) {
            parts.insert(parts.begin(), "A1");
            carry = false;
        }
        --position;
    }
}

// ����� ��� ���������� ����� ������
bool IdentifierGenerator::IncrementPart(std::string& part) {
    int letter_pos = allowed_letters.find(part[0]);
    int digit_pos = allowed_digits.find(part[1]);

    // ������� � ��������� �����
    if (digit_pos + 1 < allowed_digits.size()) {
        part[1] = allowed_digits[digit_pos + 1];
        return false; // ��� ��������
    }
    else {
        part[1] = allowed_digits[0]; // ����� ����� � �������

        // ������� � ��������� �����
        if (letter_pos + 1 < allowed_letters.size()) {
            part[0] = allowed_letters[letter_pos + 1];
            return false; // ��� ��������
        }
        else {
            part[0] = allowed_letters[0]; // ����� �����
            return true; // �������
        }
    }
}