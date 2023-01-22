#include <iostream>

unsigned long long fib(unsigned long value, unsigned long long* fib_arr)
{
	unsigned long long result = 0, iter_1 = 0, iter_2 = 1;
	if (0 == value) {
		fib_arr[0] = 0;
		return 0;
	}
	else if (1 == value) {
		fib_arr[1] = 1;
		return 1;
	}
	else {
		fib_arr[0] = 0;
		fib_arr[1] = 1;
		for (unsigned long long iter = 2; iter <= value; ++iter) {
		
			fib_arr[iter] = fib_arr[iter - 2] + fib_arr[iter - 1];
			
		}
		return fib_arr[value];
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	unsigned int number = 0;
	std::cout << "Введите число: "; std::cin >> number;
	static unsigned long long* fib_arr = new unsigned long long[number];
	std::cout << fib(number, fib_arr) << "\n";
	std::cout << "Числа Фибоначчи: ";
	for (unsigned int iter = 0; iter <= number; ++iter) {
		std::cout << fib_arr[iter] << " ";
	}
	return 0;
}