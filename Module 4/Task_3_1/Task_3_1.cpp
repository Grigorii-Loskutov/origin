// Task_3_1.cpp : Задача 1. Умный массив
// https://github.com/netology-code/cppl-homeworks/tree/main/03/01

#include <iostream>
#include <exception>
#include <string>
#include <windows.h>


class smart_array {
private:
	int N;
	int* arr;
	int curent_index;
public:
	smart_array(int arr_size) {
		this->N = arr_size;
		this->arr = new int[N] {};
		this->curent_index = 0;
	}
	void add_element(int element) {
		if (this->curent_index > (N - 1)) {
			throw std::runtime_error("maximum index reached");
		}
		arr[this->curent_index] = element;
		this->curent_index++;
	}
	int get_element(int index) {
		if ((index < 0) || (index > N - 1)) {
			std::string buf = std::to_string(index);
			throw std::runtime_error("index " + buf + " out of range");
		}
		return arr[index];
	}
	~smart_array() {
		delete[] this->arr;
	}
};


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(10) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}