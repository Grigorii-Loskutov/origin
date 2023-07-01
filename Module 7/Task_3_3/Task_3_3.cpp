// Task_3_3.cpp : Задание 3. Паттерн «Цепочка ответственности»
// https://github.com/netology-code/dpcpp-homeworks/blob/main/03/readme.md

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

enum class MessageType {
	Warning,
	Error,
	FatalError,
	Unknown
};

class LogMessage {
private:
    MessageType type_;
    std::string message_;

public:
    LogMessage(MessageType type, const std::string& message)
        : type_(type), message_(message) {}

    MessageType type() const {
        return type_;
    }

    const std::string& message() const {
        return message_;
    }
};

class BaseHandler {
private:
    BaseHandler* nextHandler_;

public:
    BaseHandler() : nextHandler_(nullptr) {}

    void setNextHandler(BaseHandler* handler) {
        nextHandler_ = handler;
    }

    void handle(const LogMessage& message) {
        if (canHandle(message)) {
            process(message);
        }
        else if (nextHandler_ != nullptr) {
            nextHandler_->handle(message);
        }
        else {
            throw std::runtime_error("Unhandled message: " + message.message());
        }
    }

protected:
    virtual bool canHandle(const LogMessage& message) = 0;
    virtual void process(const LogMessage& message) = 0;
};

class FatalErrorHandler : public BaseHandler {
protected:
    bool canHandle(const LogMessage& message) override {
        return message.type() == MessageType::FatalError;
    }

    void process(const LogMessage& message) override {
        throw std::runtime_error("Fatal Error: " + message.message());
    }
};

class ErrorHandler : public BaseHandler {
private:
    std::ofstream file_;

public:
    explicit ErrorHandler(const std::string& filePath) {
        file_.open(filePath);
    }

    ~ErrorHandler() {
        file_.close();
    }

protected:
    bool canHandle(const LogMessage& message) override {
        return message.type() == MessageType::Error;
    }

    void process(const LogMessage& message) override {
        file_ << "Error: " << message.message() << std::endl;
    }
};

class WarningHandler : public BaseHandler {
protected:
    bool canHandle(const LogMessage& message) override {
        return message.type() == MessageType::Warning;
    }

    void process(const LogMessage& message) override {
        std::cout << "Warning: " << message.message() << std::endl;
    }
};

class UnknownMessageHandler : public BaseHandler {
protected:
    bool canHandle(const LogMessage& message) override {
        return message.type() == MessageType::Unknown;
    }

    void process(const LogMessage& message) override {
        throw std::runtime_error("Unknown Message: " + message.message());
    }
};

void processLogMessage(BaseHandler& handler, const LogMessage& message) {
    handler.handle(message);
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    try
    {
        FatalErrorHandler fatalErrorHandler;
        ErrorHandler errorHandler("error.log");
        WarningHandler warningHandler;
        UnknownMessageHandler unknownMessageHandler;

        errorHandler.setNextHandler(&warningHandler);
        warningHandler.setNextHandler(&fatalErrorHandler);
        fatalErrorHandler.setNextHandler(&unknownMessageHandler);

        LogMessage logMessage1(MessageType::Warning, "This is a warning.");
        processLogMessage(errorHandler, logMessage1);

        LogMessage logMessage2(MessageType::Error, "This is an error.");
        processLogMessage(errorHandler, logMessage2);

        LogMessage logMessage3(MessageType::FatalError, "This is a fatal error.");
        processLogMessage(errorHandler, logMessage3);

        LogMessage logMessage4(MessageType::Unknown, "This is an unknown message.");
        processLogMessage(errorHandler, logMessage4);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

	return 0;
}
