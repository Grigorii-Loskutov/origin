// Task_9_2.cpp : Задача 2. Большие числа
// https://github.com/netology-code/cppl-homeworks/tree/main/11/02

#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

class huge_int_adder_over_string
{
    char* cstring;
public:
    huge_int_adder_over_string(const char* s = "") : cstring(nullptr)
    {
        if (s) {
            std::size_t n = std::strlen(s) + 1;
            cstring = new char[n];
            std::memcpy(cstring, s, n);
        }
    }
    ~huge_int_adder_over_string() // деструктор
    {
        delete cstring;
        //std::cout << "dest called" << "\n";
    }
    huge_int_adder_over_string(const huge_int_adder_over_string& other) // конструктор копирования
        : huge_int_adder_over_string(other.cstring) {}
    huge_int_adder_over_string(huge_int_adder_over_string&& other) noexcept // конструктор перемещения
        : cstring(std::exchange(other.cstring, nullptr)) {}
    huge_int_adder_over_string& operator=(const huge_int_adder_over_string& other) // оператор копирующего присваивания
    {
        return *this = huge_int_adder_over_string(other);
    }
    huge_int_adder_over_string& operator=(huge_int_adder_over_string&& other) noexcept // оператор перемещающего присваивания
    {
        std::swap(cstring, other.cstring);
        return *this;
    }
    huge_int_adder_over_string& operator+(huge_int_adder_over_string& other) // оператор сложения двух huge_int
    {
        //алгоритм сложения столбиком -- подсмотрел
        std::string str1(cstring);
        std::string str2(other.cstring);
        if (str1.length() > str2.length())
            swap(str1, str2);

        // Take an empty string for storing result
        std::string str = "";

        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;

        // Initially take carry zero
        int carry = 0;

        // Traverse from end of both strings
        for (int i = n1 - 1; i >= 0; i--)
        {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((str1[i] - '0') +
                (str2[i + diff] - '0') +
                carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // Add remaining digits of str2[]
        for (int i = n2 - n1 - 1; i >= 0; i--)
        {
            int sum = ((str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // Add remaining carry
        if (carry)
            str.push_back(carry + '0');

        // reverse resultant string
        reverse(str.begin(), str.end());
        return *this = huge_int_adder_over_string(str.c_str());
    }
    huge_int_adder_over_string& operator*(const int mult) // оператор умножения huge_int на int
    {
        for (int iter = 1; iter < mult; ++iter) {
            *this = *this + *this;
        }
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const huge_int_adder_over_string& dt) //переопределение оператора << по рекомендациям microsoft
    {
        os << dt.cstring;
        return os;
    }

};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    std::string str1 = "1";
    std::string str2 = "55";

    auto number1 = huge_int_adder_over_string(str1.c_str());
    auto number2 = huge_int_adder_over_string(str2.c_str());
    auto number3 = (number1 + number2); //почему-то number1 становится равным number4
    std::cout << number3;
    std::cout << "\n";
    auto number4 = number3 * 2;
    std::cout << number4;
    return 0;
}
