// Task_5_2.cpp :Задача 2. Таблица
// https://github.com/netology-code/cppl-homeworks/tree/main/05/02

#include <iostream>
#include <windows.h>

template <class T>
class table {
private:
	int rows;
	int cols;
	T** arr;
public:
	/*table(const table& other) = delete;
	table& operator=(const table& other) = delete;*/
	table (const int rows, const int cols) {
		this->rows = rows;
		this->cols = cols;
		this->arr = new T* [rows];
		for (int iter = 0; iter < rows; iter++) {
			arr[iter] = new T[cols];
		}
		for (int iter_r = 0; iter_r < rows; iter_r++) {
			for (int iter_c = 0; iter_c < cols; iter_c++) {
				arr[iter_r][iter_c] = 0;
			}
		}
	}
	const int Size(const char dim) {
		if ('r' == dim) {
			return rows;
		}
		else if ('c' == dim) {
			return cols;
		}
		else return 0;
	}
	class Proxy {
	public:
		Proxy(T* array) : array(array) {}
		~Proxy() = default;
		T& operator[] (int index) {
			return array[index];
		}
		const T operator[] (int index) const {
			return array[index];
		}
	private:
		T* array;
	};

	Proxy operator[](int index) {
		return Proxy(arr[index]);

	}
	const Proxy operator[](int index) const {
		return Proxy(arr[index]);
	}
	~table() {
		for (int iter = 0; iter < rows; iter++) {
			delete[] arr[iter];
		}
		delete[] arr;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	auto test_table = table<double>(2,3);
	auto a = test_table[1][1];
	test_table[1][1] = 5;
	std::cout << test_table[1][1] << "\n";
	std::cout << test_table.Size('r') << "\n";
	std::cout << test_table.Size('c') << "\n";
}

