// Task_2.cpp : Домашнее задание к занятию «Структурные шаблоны: Proxy, Decorator, Adapter». Задание 1
// https://github.com/netology-code/dpcpp-homeworks/tree/main/02#readme

#include <iostream>
#include <string>
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

class Paragraph : public DecoratedText {
public:
	explicit Paragraph(Text* text) : DecoratedText(text) {}
	void render(const std::string& data) const {
		std::cout << "<p>";
		text_->render(data);
		std::cout << "</p>";
	}
};

class Reversed : public DecoratedText {
public:
	explicit Reversed(Text* text) : DecoratedText(text) {}
	void render(const std::string& data) const {
		std::string temp_str = data;
		std::reverse(std::begin(temp_str), std::end(temp_str));
		text_->render(temp_str);		
	}
};

class Link : public DecoratedText {
public:
	explicit Link(Text* text) : DecoratedText(text) {}
	void render(const std::string& domen, const std::string& link) const {
		std::string temp_str = "<a href=" + domen + ">" + link + "</a>";
		text_->render(temp_str);
	}
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	auto text_block = new ItalicText(new BoldText(new Text()));
	text_block->render("Hello world");
	std::cout << "\n";
	auto text_block_1 = new Paragraph(new Text());
	text_block_1->render("Hello world");
	std::cout << "\n";
	auto text_block_2 = new Reversed(new Text());
	text_block_2->render("Hello world");
	std::cout << "\n";
	auto text_block_3 = new Link(new Text());
	text_block_3->render("netology.ru", "Hello world");

}

