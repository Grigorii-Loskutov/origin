// Task_3_1.cpp : Задание 1. Паттерн «Команда»
// https://github.com/netology-code/dpcpp-homeworks/tree/main/03

#include <iostream>
#include <fstream>
#include <windows.h>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class FileLogCommand : public LogCommand {
public:
    explicit FileLogCommand(const std::string& filePath) : filePath_(filePath) {}

    void print(const std::string& message) override {
        std::ofstream file(filePath_, std::ios::app);
        if (file.is_open()) {
            file << message << std::endl;
            file.close();
        }
        else {
            std::cout << "Failed to open file: " << filePath_ << std::endl;
        }
    }

private:
    std::string filePath_;
};

void print(LogCommand& command) {
    command.print("Executing command...");
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russia");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ConsoleLogCommand consoleCommand;
    FileLogCommand fileCommand("log.txt");

    print(consoleCommand);
    print(fileCommand);
}

