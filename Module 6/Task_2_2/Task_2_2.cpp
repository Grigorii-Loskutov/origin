// Task_2_1.cpp : «Прогресс бар»
// https://github.com/netology-code/map-homeworks/tree/main/02

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std::chrono_literals;

std::mutex mtx;
void calc_simulator(int duration, int thread_num, std::vector<std::vector<char>>& bars, std::vector<bool>& flag_refresh, std::vector<bool>& flag_finish) {
	bool refresh = true;
	double elapsed_time = 0;
	while (bars[thread_num].size() < duration)
	{
		auto start_time = std::chrono::high_resolution_clock::now();
		bars[thread_num].push_back('%');
		mtx.lock();
		refresh = true;
		for (auto iter : flag_refresh) {
			refresh = refresh && iter;
		}
		if (refresh == true)
		{
			system("cls");
			for (auto iter : flag_refresh) {
				iter = false;
			}
		}
		std::cout << thread_num << " " << "treadID:\t" << std::this_thread::get_id() << "\t";
		auto print = [](auto& n) { std::cout << n; };
		std::for_each(bars[thread_num].begin(), bars[thread_num].end(), print);
		if (bars[thread_num].size() == duration)
		{
			std::cout << "\tElapsed Time (ms): " << elapsed_time;
		}
		flag_refresh[thread_num] = true;
		std::cout << std::endl;
		mtx.unlock();
		srand(time(nullptr));
		int sleep = rand() % 1000;
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
		auto end_time = std::chrono::high_resolution_clock::now();
		elapsed_time = elapsed_time + std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
	}
	flag_finish[thread_num] = true;
}

void megaPrint(std::vector<std::vector<char>>& bars, std::vector<bool>& flag_refresh, std::vector<bool>& flag_finish, int& treads_quantity) {
	bool finish = flag_finish[0];

	while(!finish)
	{
		mtx.lock();
		for (auto iter : flag_finish) {
			finish = finish && iter;
		}
		bool refresh = true;
		for (auto iter : flag_refresh) {
			refresh = refresh && iter;
		}
		if (refresh == true)
		{
			std::cout << std::endl << "refresh";
			system("cls");
			for (auto iter : flag_refresh) {
				iter = false;
			}
			for (int iter = 0; iter < treads_quantity; iter++)
			{
				std::cout << iter << " ";
				auto print = [](auto& n) { std::cout << n; };
				std::for_each(bars[iter].begin(), bars[iter].end(), print);
				std::cout << std::endl;
			}
		}
		mtx.unlock();
		std::this_thread::sleep_for(10ms);
	}
	std::cout << std::endl << "finish";
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
	std::cout << "Введите количество итераций (1 итерация - 1с для одного потока): ";
	std::cin >> calc_duration;
	std::vector<std::thread> threads;
	std::vector<bool> flag_refresh;
	std::vector<bool> flag_finish;
	std::vector<std::vector<char>> bars;
	
	for (int i = 0; i < treads_quantity; ++i) {
		flag_refresh.push_back(false);
		flag_finish.push_back(false);
		std::vector<char> bar;
		bars.push_back(bar);
		threads.emplace_back(calc_simulator, calc_duration, i, std::ref(bars), std::ref(flag_refresh), std::ref(flag_finish));
	}
	for (auto& thread : threads) {
		thread.join();
	}
	return 0;
}