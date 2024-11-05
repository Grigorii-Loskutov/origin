#pragma once
#include <string>
#include <vector>

class IdentifierGenerator
{
public:
	// �������� ����� ��������� ���������� ��������������
	std::string GenerateNextIdentifier(const std::string& identifier);
private:
	// ����� ��� ��������� �������������� �� ������
	std::vector<std::string> SplitIdentifier(const std::string& identifier);

	// ����� ��� ���������� ����� ������� � ������
	std::string JoinIdentifier(const std::vector<std::string>& parts);

	// ����� ��� ���������� ��������������
	void IncrementIdentifier(std::vector<std::string>& parts);

	// ����� ��� ���������� ����� ������
	bool IncrementPart(std::string& part);

	// ����� ���������� ���� � ����
	const std::string allowed_letters = "ABCEHIKLNPRSTUWXYZ";
	const std::string allowed_digits = "123456789";
};

