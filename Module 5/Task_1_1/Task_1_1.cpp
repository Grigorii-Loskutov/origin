// Task_1_1.cpp : «Очередь клиентов»
// https://github.com/netology-code/map-homeworks/blob/main/01/readme.md

#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
using namespace std::chrono_literals;

void client(unsigned& clients, unsigned& max_clients)
{
	while (max_clients > 0) {
		clients++;
		max_clients--;
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hConsole, 15);
		system("cls");
		std::cout << "Количество клиентов, которых осталось обслужить: " << max_clients << std::endl;
		std::cout << "Количество клиентов в очереди: " << clients << std::endl;
		std::this_thread::sleep_for(1000ms);
	}
}

void cassir(unsigned& clients, unsigned& max_clients)
{
	while (clients > 0) {
		clients--;
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hConsole, 15);
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
	unsigned max_clients = 0;
	//thread_local 
	unsigned clients = 0; // текущее значение клиентов в очереди
	std::cout << "Введите количество клиентов, которое будет обслужено: "; std::cin >> max_clients;
	std::thread t1(client, std::ref(clients), std::ref(max_clients));
	std::thread t2(cassir, std::ref(clients), std::ref(max_clients));
	t1.join();
	t2.join();
}

