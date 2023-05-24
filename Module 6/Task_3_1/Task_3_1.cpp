// Task_3_1.cpp : «Сортировка выбором»
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <thread>
#include <mutex>
#include <future>
#include <random>


//Функция генерации вектора размерностью N случайных чисел равномерного распределения в диапазоне от 0 до range
std::vector<int> randomNumber(int range, int N) {
	std::vector<int> result;
	for (int iter = 0; iter < N; iter++)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(0, range);
		result.push_back(dist(gen));
	}
	return result;
}

//Функция вывода вектора на экран
template <class T>
void print(const std::vector<T>& vec) {
	auto it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n";
}

void findMin(std::vector<int>& data, std::promise<std::vector<int>::iterator>& promiseObj) {

	std::vector<int>::iterator minimum = std::min_element(data.begin(), data.end());
	promiseObj.set_value(minimum);
}


int main(int argc, char** argv)
{

	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//создадим вектор случайных значений
	std::vector<int> unsortVector = randomNumber(100, 30); //Для сортировки в одном потоке
	std::vector<int> unsortVector_A = unsortVector; //Для сортировки с помощью promise
	std::cout << "Unsorted random vector: "; print(unsortVector);
	std::vector<int> sortVector{}; //Для сортровки в одном потоке
	std::vector<int> sortVector_A{}; //Для сортировки с помощью promise
	//Сделаем сортировку в одном потоке
	while (unsortVector.size() > 0) {
		std::vector<int>::iterator minimum = std::min_element(unsortVector.begin(), unsortVector.end());
		sortVector.push_back(*minimum);
		unsortVector.erase(minimum);
	}
	std::cout << "Sorted vector (1 trhread): "; print(sortVector);

	//Сделаем сортировку с помощью асинхронных вызовов


	while (unsortVector_A.size() > 0)
	{
		// Создаем promise для передачи результата
		std::promise<std::vector<int>::iterator> promiseObj;

		// Получаем future, связанный с promise
		std::future<std::vector<int>::iterator> futureObj = promiseObj.get_future();

		// Запускаем функцию asyncFunction в асинхронном режиме,
	   // передавая вектор и promise по ссылке
		std::thread t(findMin, std::ref(unsortVector_A), std::ref(promiseObj));
		// Ждем завершения функции и получаем результат
		std::vector<int>::iterator minimum = futureObj.get();
		sortVector_A.push_back(*minimum);
		unsortVector_A.erase(minimum);
		t.join();
	}
	std::cout << "Sorted vector (promise trhread): "; print(sortVector_A);

	return 0;
}
