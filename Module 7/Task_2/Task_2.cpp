// Task_2.cpp : Домашнее задание к занятию «Структурные шаблоны: Proxy, Decorator, Adapter»
// https://github.com/netology-code/dpcpp-homeworks/tree/main/02#readme

#include <iostream>
#include <iostream>
#include <windows.h>

class Text {
public:
	virtual void render(const std::string& data) const {
		std::cout << data;
	}
};

class DecoratedText : public Text {
public:
	explicit DecoratedText(Text* text) : text_(text) {}
	Text* text_;
};

class ItalicText : public DecoratedText {
public:
	explicit ItalicText(Text* text) : DecoratedText(text) {}
	void render(const std::string& data)  const {
		std::cout << "<i>";
		text_->render(data);
		std::cout << "</i>";
	}
};

class BoldText : public DecoratedText {
public:
	explicit BoldText(Text* text) : DecoratedText(text) {}
	void render(const std::string& data) const {
		std::cout << "<b>";
		text_->render(data);
		std::cout << "</b>";
	}
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	auto text_block = new ItalicText(new BoldText(new Text()));
	text_block->render("Hello world");
}

