// Task_1_2.cpp : «Параллельные вычисления»
// https://github.com/netology-code/map-homeworks/blob/main/01/readme.md

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <chrono>
#include <thread>
#include <omp.h>

std::vector<int> random_vector(int size) {
    srand(time(nullptr));
    int range = 100;
    std::vector<int> rand_v;
    for (int i = 0; i < size; i++) {
        rand_v.push_back(rand() % range);
    }
    return rand_v;
}

std::vector<int> add_vectors(const std::vector<int>& a, const std::vector<int>& b, int num_threads) {
    int n = a.size();
    std::vector<int> c(n);

#pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }

    return c;
}

int main(int argc, char** argv)
{	
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    std::vector<int> v1_1000 = random_vector(1000);
    std::vector<int> v2_1000 = random_vector(1000);
    std::vector<int> v1_10000 = random_vector(10000);
    std::vector<int> v2_10000 = random_vector(10000);
    std::vector<int> v1_100000 = random_vector(100000);
    std::vector<int> v2_100000 = random_vector(100000);
    std::vector<int> v1_1000000 = random_vector(1000000);
    std::vector<int> v2_1000000 = random_vector(1000000);
    /*auto print = [](auto& n) { std::cout << n << "\n"; };
    std::for_each(v1_1000.begin(), v1_1000.end(), print);*/
    unsigned int CPU_number = std::thread::hardware_concurrency();
    std::cout << "Number of cores: " << CPU_number << std::endl;
    std::vector<int> results;
    for (int num_threads = 1; num_threads <= CPU_number; num_threads *= 2) {
        auto start_time = std::chrono::high_resolution_clock::now();

        std::vector<int> c = add_vectors(v1_1000000, v2_1000000, num_threads);

        auto end_time = std::chrono::high_resolution_clock::now();
        double duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

        results.push_back(duration);
    }
    for (int i = 0; i < results.size(); i++) {
        std::cout << (i + 1) << "\t\t" << results[i] << std::endl;
    }
}
