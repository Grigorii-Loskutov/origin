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
void calc_simulator(double duration, int thread_num, std::vector<bool>& flag_refreh, std::vector<bool>& flag_finish) {
	std::vector<char> bar {};
	while (bar.size() < duration)
	{
		bar.push_back('%');
		mtx.lock();
		//if (thread_num == 0) { system("cls"); }
		/*switch (color)
		{
		case 1: system("Color 09"); break;
		case 2: system("Color 0A"); break;
		case 3: system("Color 0B"); break;
		case 4: system("Color 0C"); break;
		case 5: system("Color 0D"); break;
		case 6: system("Color 0E"); break;
		case 7: system("Color 0F"); break;
		case 8: system("Color 08"); break;
		default:
			break;
		}*/
		std::cout << thread_num << " " << "treadID:\t" << std::this_thread::get_id() << "\t";
		auto print = [](auto& n) { std::cout << n; };
		std::for_each(bar.begin(), bar.end(), print);
		std::cout << std::endl;
		flag_refreh[thread_num] = true;
		mtx.unlock();
		srand(time(nullptr));
		int sleep = rand() % 1000;
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
	}
	flag_finish[thread_num] = true;
}

void clear(std::vector<bool>& flag_refresh, std::vector<bool>& flag_finish) {
	bool refresh = true;
	bool finish = false;
	//auto if_refresh = [&refresh](bool& n) {refresh = refresh && n; };
	//std::for_each(flag.begin(), flag.end(), if_refresh);
	while(!finish)
	{
		//finish = true;
		mtx.lock();
		for (auto iter : flag_finish) {
			finish = finish && iter;
		}
		for (auto iter : flag_refresh) {
			refresh = refresh && iter;
			//std::cout << std::endl << "refresh";
		}
		if (refresh == true)
		{
			std::cout << std::endl << "refresh";
			system("cls");
			for (auto iter : flag_refresh) {
				iter = false;
			}
		}
		mtx.unlock();
		std::this_thread::sleep_for(500ms);
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
	/*auto start_time = std::chrono::high_resolution_clock::now();
	auto end_time = std::chrono::high_resolution_clock::now();
	double duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();*/
	/*std::thread t1 (calc_simulator, calc_duration, treads_quantity);
	t1.join();*/
	std::vector<std::thread> threads;
	std::vector<bool> flag_refresh;
	std::vector<bool> flag_finish;
	
	for (int i = 0; i < treads_quantity; ++i) {
		flag_refresh.push_back(false);
		flag_finish.push_back(false);
		threads.emplace_back(calc_simulator, calc_duration, i, std::ref(flag_refresh), std::ref(flag_finish));
	}
	for (auto& thread : threads) {
		thread.join();
	}
	std::thread refresh_tread(clear, std::ref(flag_refresh), std::ref(flag_finish));
	refresh_tread.join();
	return 0;
}