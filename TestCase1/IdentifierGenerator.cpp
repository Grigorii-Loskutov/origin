#include "IdentifierGenerator.h"
#include  <iostream>
// �������� ����� ��������� ���������� ��������������
std::string IdentifierGenerator::GenerateNextIdentifier(const std::string& identifier) {
	std::vector<std::string> IndetifiersVector;
	std::string copyIdentifier = identifier; // ���������, �.�. �������� �� const
	IndetifiersVector = IdentifierGenerator::SplitIdentifier(copyIdentifier);
	IdentifierGenerator::IncrementIdentifier(IndetifiersVector);
	std::string outIdentifier = IdentifierGenerator::JoinIdentifier(IndetifiersVector);
	return outIdentifier;
}

// ����� ��� ��������� �������������� �� ������
std::vector<std::string> IdentifierGenerator::SplitIdentifier(std::string& identifier) {
	std::vector<std::string> IndentifiersOutVector; // �������� ������ ���������������
	std::string::iterator IT = identifier.begin();
	while (IT != identifier.end()) {
		std::string OneIndentofierString;
		if (allowed_letters.find(*IT) != std::string::npos) {
			OneIndentofierString.push_back(*IT);
			if (IT != identifier.end()) {
				IT++;
				if (IT == identifier.end()) { continue; }
			}
			else { continue; }
		}
		else { break; }
		if (allowed_digits.find(*IT) != std::string::npos) {
			OneIndentofierString.push_back(*IT);
			IndentifiersOutVector.push_back(OneIndentofierString); // ��������� ������ ��������� ��������� �����
			if (IT != identifier.end()) {
				IT++;
				if (IT == identifier.end()) { continue; }
			}
			else { continue; }
		}
		else { break; }
		if (*IT == '-') {
			IT++;
			if (IT == identifier.end()) { continue; }
		}
	}
	return IndentifiersOutVector;
}

// ����� ��� ���������� ����� ������� � ������
std::string IdentifierGenerator::JoinIdentifier(const std::vector<std::string>& parts) {
	std::string outStringIdentifier;
	for (const auto& IT : parts) {
		outStringIdentifier += IT;
		outStringIdentifier.push_back('-');
	}
	if (!outStringIdentifier.empty()) { outStringIdentifier.pop_back(); }
	return outStringIdentifier;
}

// ����� ��� ���������� ��������������
void IdentifierGenerator::IncrementIdentifier(std::vector<std::string>& parts) {
	std::vector<std::string>::iterator IT = parts.end();
	while (IT != parts.begin()) {
		IT--;
		if (!IdentifierGenerator::IncrementPart(*IT)) {
			break;
		}
		else {
			if (IT == parts.begin()) {
				parts.insert(parts.begin(), "A1");
				//parts.push_back("A1");
				break;
			}
		}
	}
}

// ����� ��� ���������� ����� ������
bool IdentifierGenerator::IncrementPart(std::string& part) {
	char letter = part[0];
	char newLetter = letter;
	char digit = part[1];
	char newDigit = digit;
	if (digit == '9') {
		newDigit = '1';
	}
	else {
		newDigit++;
	}
	if (newDigit == '1') { // ����� ��������� �����
		if (letter == 'Z') {
			newLetter = 'A';
			part[0] = newLetter;
			part[1] = newDigit;
			return true;		// ����������� ����� �� 'A', ������� ����� ��������� ���������� ����� ��������������
		}
		else {
			newLetter++;
			if (newLetter == 'D' || newLetter == 'G' || newLetter == 'J' || newLetter == 'M' || newLetter == 'Q' || newLetter == 'V') {
				newLetter++;
			}
			if (newLetter == 'F') {
				newLetter++;
				newLetter++;
			}
			part[0] = newLetter;
			part[1] = newDigit;
			return false;		// ���������� ����� �������������� ���������������� �� ���������
		}
	}
	else {
		part[0] = newLetter;
		part[1] = newDigit;
		return false;		// ���������� ����� �������������� ���������������� �� ���������
	}
}
