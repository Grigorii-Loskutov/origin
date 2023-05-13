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
    unsigned int CPU_number = std::thread::hardware_concurrency();
    std::cout << "Number of cores: " << CPU_number << std::endl;
    std::vector<std::vector<int>> results_2dim;
    const int low = 1'000;
    const int high = 1'000'000'0;
    std::cout << "\t\t";
    for (int range_iter = low; range_iter <= high; range_iter *= 10) {
        std::vector<int> v1 = random_vector(range_iter);
        std::vector<int> v2 = random_vector(range_iter);
        std::cout << range_iter << "\t\t";
        std::vector<int> results_1dim;
        for (int num_threads = 1; num_threads <= CPU_number; num_threads *= 2) {
            auto start_time = std::chrono::high_resolution_clock::now();

            std::vector<int> c = add_vectors(v1, v2, num_threads);

            auto end_time = std::chrono::high_resolution_clock::now();
            double duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

            results_1dim.push_back(duration);
        }
        results_2dim.push_back(results_1dim);
    }
    std::cout << std::endl;
    std::vector<std::vector<int>> results_2dim_tr(results_2dim[0].size(), std::vector<int>(results_2dim.size()));
    std::transform(results_2dim.begin(), results_2dim.end(), results_2dim_tr.begin(),
        [](const std::vector<int>& row) {
            return std::vector<int>(row.begin(), row.end());
        });
    int treads = 1;
    for (int i = 0; i < results_2dim[0].size(); i++) {
        std::cout << treads << " threads:\t";
        for (int j = 0; j < results_2dim.size(); j++) {
            std::cout << results_2dim[j][i] << "\t\t";
        }
        std::cout << std::endl;
        treads *= 2;
    }
}
