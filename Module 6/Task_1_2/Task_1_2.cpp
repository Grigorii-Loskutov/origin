// Task_1_2.cpp : «Параллельные вычисления»
// https://github.com/netology-code/map-homeworks/blob/main/01/readme.md

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex mtx;
std::vector<int> random_vector(int size) {
    srand(time(nullptr));
    int range = 100;
    std::vector<int> rand_v;
    for (int i = 0; i < size; i++) {
        rand_v.push_back(rand() % range);
    }
    return rand_v;
}

void sum_vectors(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& result, int start, int end) {
    for (int i = start; i < end; ++i) {
        mtx.lock();
        result[i] = a[i] + b[i];
        mtx.unlock();
    }
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
        std::vector<int> c(range_iter);
        std::cout << range_iter << "\t\t";
        std::vector<int> results_1dim;
        for (int num_threads = 1; num_threads <= CPU_number; num_threads *= 2) {
            auto start_time = std::chrono::high_resolution_clock::now();
            std::vector<std::thread> threads;
            for (int i = 0; i < num_threads; ++i) {
                int start = i * range_iter / num_threads;
                int end = (i + 1) * range_iter / num_threads;
               
                threads.emplace_back(sum_vectors, std::ref(v1), std::ref(v2), std::ref(c), start, end);
            }
           for (auto& thread : threads) {
                thread.join();
            }
            auto end_time = std::chrono::high_resolution_clock::now();
            double duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

            results_1dim.push_back(duration);
        }
        results_2dim.push_back(results_1dim);
    }
    std::cout << std::endl;
 /*   std::vector<std::vector<int>> results_2dim_tr(results_2dim[0].size(), std::vector<int>(results_2dim.size()));
    std::transform(results_2dim.begin(), results_2dim.end(), results_2dim_tr.begin(),
        [](const std::vector<int>& row) {
            return std::vector<int>(row.begin(), row.end());
        });*/
    int thread_num = 1;
    for (int i = results_2dim[0].size()-1; i >=0; i--) {
        std::cout << thread_num << " threads:\t";
        for (int j = 0; j < results_2dim.size(); j++) {
            std::cout << results_2dim[j][i] << "\t\t";
        }
        std::cout << std::endl;
        thread_num *= 2;
    }
}
