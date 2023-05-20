// Task_2_1.cpp : «Атомарная очередь клиентов»
// https://github.com/netology-code/map-homeworks/tree/main/02

#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <atomic>
using namespace std::chrono_literals;

void client(std::atomic<int>& clients, std::atomic<int>& max_clients)
{
	while (max_clients > 0) {
		clients.fetch_add(1);
		max_clients.fetch_sub(1);
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hConsole, 15);
		system("cls");
		std::cout << "Количество клиентов, которых осталось обслужить: " << max_clients << std::endl;
		std::cout << "Количество клиентов в очереди: " << clients << std::endl;
		std::this_thread::sleep_for(1000ms);
	}
}

void cassir(std::atomic<int>& clients, std::atomic<int>& max_clients)
{
	while (clients > 0) {
		clients.fetch_sub(1);
		system("cls");
		std::cout << "Количество клиентов, которых осталось обслужить: " << max_clients << std::endl;
		std::cout << "Количество клиентов в очереди: " << clients << std::endl;
		std::this_thread::sleep_for(2000ms);
	}
}


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int temp_int;
	std::atomic<int> clients{ 0 }; // текущее значение клиентов в очереди
	std::cout << "Введите количество клиентов, которое будет обслужено: "; std::cin >> temp_int;
	std::atomic<int> max_clients{ temp_int };
	std::thread t1(client, std::ref(clients), std::ref(max_clients));
	std::thread t2(cassir, std::ref(clients), std::ref(max_clients));
	t1.join();
	t2.join();
}