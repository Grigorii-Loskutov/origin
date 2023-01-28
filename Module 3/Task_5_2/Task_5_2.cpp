// Task_5_2.cpp : Задача 2. «Путешествие» по пирамиде
//https://github.com/netology-code/algocpp-homeworks/tree/main/5/02

#include <iostream>
#include <string.h>
#include <windows.h>

bool go_right(int* arr, int* size_of_arr, int* current_index, int* current_layer, int* current_parent_index, std::string* current_node) {
	int new_right = 2 * *current_index + 2;
	if ((new_right < *size_of_arr) && (new_right > 0)) {
		*current_parent_index = *current_index;
		*current_index = new_right;
		*current_layer = *current_layer + 1;
		*current_node = "right";
		return true;
	}
	else {
		return false;
	}
}

bool go_left(int* arr, int* size_of_arr, int* current_index, int* current_layer, int* current_parent_index, std::string* current_node) {
	int new_left = 2 * *current_index + 1;
	if ((new_left < *size_of_arr) && (new_left > 0)) {
		*current_parent_index = *current_index;
		*current_index = new_left;
		*current_layer = *current_layer + 1;
		*current_node = "left";
		return true;
	}
	else {
		return false;
	}
}

bool go_up(int* arr, int* size_of_arr, int* current_index, int* current_layer, int* current_parent_index, std::string* current_node) {
	if (*current_index == 0) return false;
	else {
		int new_node = (*current_index - 1) / 2;
		*current_index = new_node;
		if (new_node == 0) {
			*current_node = "root";
			*current_index = new_node;
			*current_layer = 0;
		}
		else {
			*current_parent_index = (*current_index - 1) / 2;
			*current_layer = *current_layer - 1;
			if (new_node % 2 == 0) {
				*current_node = "right";
			}
			else {
				*current_node = "left";
			}
		}
		return true;
	}
}

void print_current_node(int* arr, int* size_of_arr, int* current_index, int* current_layer, int* current_parent_index, std::string* current_node) {
	if (*current_index == 0) {
		std::cout << *current_layer << " " << *current_node << " " << arr[*current_index] << "\n";
	}
	else {
		std::cout << *current_layer << " " << *current_node << "(" << arr[*current_parent_index] << ") " << arr[*current_index] << "\n";
	}
}

void print_pyramid(int* arr, int size) {
	std::cout << "Пирамида:\n";
	int layer = 0;
	std::cout << layer << " root " << arr[0] << "\n";
	layer++;
	int parent = 0;
	int left = 0;
	int right = 0;
	int iter = 0;
	int parent_count = 1;
	bool exit = false;
	while (!exit) {
		parent = (iter - 1) / 2;
		left = 2 * iter + 1;
		if (left != size) {
			exit = false;
			std::cout << layer << " " << " left(" << arr[iter] << ") " << arr[left] << "\n";
		}
		else {
			exit = true;
		}
		right = 2 * iter + 2;
		if (right != size) {
			exit = false;
			std::cout << layer << " " << " right(" << arr[iter] << ") " << arr[right] << "\n";
		}
		else {
			exit = true;
		}
		parent_count++;
		if (parent_count % 2 == 0) layer++;
		iter++;
	}
}

void print_array(int* arr, int size) {
	std::cout << "Исходный массив: ";
	for (unsigned iter = 0; iter < size; iter++) {
		std::cout << arr[iter] << " ";
	}
	std::cout << "\n";
}

enum comands {
	right,
	left,
	up,
	exit_,
	null_command
};

//const std::string right = "right";
//const std::string left = "left";
//const std::string up = "up";
//const std::string exit = "exit";
static int current_index = 0;
static int current_layer = 0;
static int current_parent_index = 0;
static std::string node = "root";
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int m1[] = { 1, 3, 6, 5, 9, 8 };
	int size_m1 = sizeof(m1) / sizeof(m1[0]);
	int m2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
	int size_m2 = sizeof(m2) / sizeof(m2[0]);
	int m3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
	int size_m3 = sizeof(m3) / sizeof(m3[0]);
	std::string comand;
	print_array(m1, size_m1);
	print_pyramid(m1, size_m1);

	comands step_comand;
	do {
		std::cout << "Вы находитесь здесь: ";
		print_current_node(m1, &size_m1, &current_index, &current_layer, &current_parent_index, &node);
		std::cout << "Введите команду: "; std::cin >> comand;
		if (comand == "right") step_comand = comands::right;
		else if (comand == "left") step_comand = comands::left;
		else if (comand == "up") step_comand = comands::up;
		else if (comand == "exit") step_comand = comands::exit_;
		else step_comand = comands::null_command;
		switch (step_comand) {
		case comands::right:
			//std::cout << "right\n";
			if (go_right(m1, &size_m1, &current_index, &current_layer, &current_parent_index, &node) == true) {
				std::cout << "Ok\n";
			}
			else {
				std::cout << "Ошибка! Отсутствует правый потомок\n";
			}
			break;
		case comands::left:
			//std::cout << "left\n";
			if (go_left(m1, &size_m1, &current_index, &current_layer, &current_parent_index, &node) == true) {
				std::cout << "Ok\n";
			}
			else {
				std::cout << "Ошибка! Отсутствует левый потомок\n";
			}
			break;
		case comands::up:
			//std::cout << "up\n";
			if (go_up(m1, &size_m1, &current_index, &current_layer, &current_parent_index, &node) == true) {
				std::cout << "Ok\n";
			}
			else {
				std::cout << "Ошибка! Отсутствует родитель\n";
			}

			break;
		case comands::exit_:
			std::cout << "exit\n";
			break;
		case comands::null_command:
			break;
		default:
			break;
		}
	} while (step_comand != comands::exit_);
	/*print_array(m2, size_m2);
	print_pyramid(m2, size_m2);
	print_array(m3, size_m3);
	print_pyramid(m3, size_m3);*/
}