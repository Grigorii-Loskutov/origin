// Task_4_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <windows.h>

class Printable
{
public:
    virtual ~Printable() = default;
    virtual std::string print() const = 0;
protected:
    std::string data_ = "aBcD";
};

class TextPrintable : public Printable
{
public:
    virtual std::string print() const override
    {
        return "Text: " + data_;
    }
};

class HTMLPrintable : public Printable
{
public:
    virtual std::string print() const override
    {
        return "<html>" + data_ + "</html>";
    }
};

class JSONPrintable : public Printable
{
public:
    virtual std::string print() const override
    {
        return "{ \"data\": \"" + data_ + "\"}";
    }
};

void saveTo(std::ofstream& file, const Printable& printable)
{
    file << printable.print();
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    std::ofstream file1("text.txt");
    TextPrintable textPrintable;
    saveTo(file1, textPrintable);
    file1.close();

    std::ofstream file2("html.txt");
    HTMLPrintable htmlPrintable;
    saveTo(file2, htmlPrintable);
    file2.close();

    std::ofstream file3("json.txt");
    JSONPrintable jsonPrintable;
    saveTo(file3, jsonPrintable);
    file3.close();
	return 0;

}

