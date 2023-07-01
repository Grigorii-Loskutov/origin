// Task_3_2.cpp : Задание 2. Паттерн «Наблюдатель»
// https://github.com/netology-code/dpcpp-homeworks/blob/main/03/readme.md

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

// Интерфейс наблюдателя
class Observer {
public:
    virtual void onWarning(const std::string& message) = 0;
    virtual void onError(const std::string& message) = 0;
    virtual void onFatalError(const std::string& message) = 0;
};

// Наблюдаемый класс
class Observable {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        // Найдем указатель на наблюдателя в векторе и удалим его
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void warning(const std::string& message) const {
        // Оповещаем наблюдателей о предупреждении
        for (Observer* observer : observers) {
            observer->onWarning(message);
        }
    }

    void error(const std::string& message) const {
        // Оповещаем наблюдателей об ошибке
        for (Observer* observer : observers) {
            observer->onError(message);
        }
    }

    void fatalError(const std::string& message) const {
        // Оповещаем наблюдателей о фатальной ошибке
        for (Observer* observer : observers) {
            observer->onFatalError(message);
        }
    }
};

// Класс для работы с предупреждениями
class WarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "Warning: " << message << std::endl;
    }

    void onError(const std::string& message) override {
        // Пустая реализация, не реагирует на ошибки
    }

    void onFatalError(const std::string& message) override {
        // Пустая реализация, не реагирует на фатальные ошибки
    }
};

// Класс для работы с ошибками
class ErrorObserver : public Observer {
private:
    std::ofstream file;

public:
    explicit ErrorObserver(const std::string& filePath) {
        file.open(filePath);
    }

    ~ErrorObserver() {
        file.close();
    }

    void onWarning(const std::string& message) override {
        // Пустая реализация, не реагирует на предупреждения
    }

    void onError(const std::string& message) override {
        file << "Error: " << message << std::endl;
    }

    void onFatalError(const std::string& message) override {
        // Пустая реализация, не реагирует на фатальные ошибки
    }
};

// Класс для работы с фатальными ошибками
class FatalErrorObserver : public Observer {
private:
    std::ofstream file;

public:
    explicit FatalErrorObserver(const std::string& filePath) {
        file.open(filePath);
    }

    ~FatalErrorObserver() {
        file.close();
    }

    void onWarning(const std::string& message) override {
        // Пустая реализация, не реагирует на предупреждения
    }

    void onError(const std::string& message) override {
        // Пустая реализация, не реагирует на ошибки
    }

    void onFatalError(const std::string& message) override {
        std::cout << "Fatal Error: " << message << std::endl;
        file << "Fatal Error: " << message << std::endl;
    }
};

// Функция для выполнения команд
void executeCommands(Observable& observable) {
    observable.warning("This is a warning message.");
    observable.error("This is an error message.");
    observable.fatalError("This is a fatal error message.");
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    Observable observable;

    WarningObserver warningObserver;
    observable.addObserver(&warningObserver);

    ErrorObserver errorObserver("error.log");
    observable.addObserver(&errorObserver);

    FatalErrorObserver fatalErrorObserver("fatal_error.log");
    observable.addObserver(&fatalErrorObserver);

    executeCommands(observable);

    observable.removeObserver(&warningObserver);
    observable.removeObserver(&errorObserver);
    observable.removeObserver(&fatalErrorObserver);

    return 0;
}