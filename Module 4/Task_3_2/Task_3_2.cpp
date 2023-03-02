// Task_3_2.cpp : Задача 2. Копирование умных массивов
// https://github.com/netology-code/cppl-homeworks/tree/main/03/02

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
	int get_element(int index) const {
		if ((index < 0) || (index > curent_index)) {
			std::string buf = std::to_string(index);
			throw std::runtime_error("index " + buf + " out of range");
		}
		return arr[index];
	}
	int get_curent_index() const {
		return this->curent_index;
	}
	int get_arr_size() const {
		return N;
	}
	void arr_copy(const smart_array &source_arr) { //передаём по ссылке, т.к. при передаче по значению происходит копирование и создаётся ещё один объект
		this->N = source_arr.get_arr_size();
		this->curent_index = source_arr.get_curent_index();
		delete[] this->arr;
		this->arr = new int[N] {};
		for (int iter = 0; iter < N; iter++) {
			this->arr[iter] = source_arr.get_element(iter);
		}
	}
	~smart_array() {
		delete[] this->arr;
	}
	smart_array& operator=(const smart_array& copyFrom) {
		smart_array::arr_copy(copyFrom);
		return *this;
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

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);
	
		//arr.arr_copy(new_array);
		arr = new_array;
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}