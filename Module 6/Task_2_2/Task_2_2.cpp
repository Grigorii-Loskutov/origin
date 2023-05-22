// Task_2_1.cpp : «Прогресс бар»
// https://github.com/netology-code/map-homeworks/tree/main/02

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>
#include <mutex>
#include <windows.h>
#include <random>

using namespace std::chrono_literals;


int randomNumber(int range) {
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<int> dist(0, range);  

	int randomNumber = dist(gen);  

	return randomNumber;
}

COORD getCursorPosition() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo);
	return bufferInfo.dwCursorPosition;
}

void setCursorPosition(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(consoleHandle, position);
}

std::mutex mtx;
void calc_simulator(int duration, int thread_num) {
	bool refresh = true;
	double elapsed_time = 0;
	int count = 0;
	int line = thread_num + 2;
	int col = 0;
	mtx.lock();
	setCursorPosition(col, line);
	std::cout << thread_num << " " << "treadID:\t" << std::this_thread::get_id() << "\t";
	col = getCursorPosition().X;
	mtx.unlock();
	while (count < duration)
	{
		auto start_time = std::chrono::high_resolution_clock::now();
		mtx.lock();
		setCursorPosition(col, line);
		std::cout << "%";
		if (count == duration - 1)
		{
			std::cout << "\tElapsed Time (ms): " << elapsed_time;
		}
		col = getCursorPosition().X;
		mtx.unlock();
		int sleep;
		sleep = randomNumber(1000);
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
		auto end_time = std::chrono::high_resolution_clock::now();
		elapsed_time = elapsed_time + std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
		count++;
	}

}



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int treads_quantity{ 1 };
	int calc_duration{ 1 };
	std::cout << "Введите количество потоков: ";
	std::cin >> treads_quantity;
	std::cout << "Введите количество итераций: ";
	std::cin >> calc_duration;
	std::vector<std::thread> threads;

	
	for (int i = 0; i < treads_quantity; ++i) {

		threads.emplace_back(calc_simulator, calc_duration, i);
	}
	for (auto& thread : threads) {
		thread.join();
	}
	setCursorPosition(0, 2 + treads_quantity);
	return 0;
}