// safe_queue.cpp : Курсовой проект «Потокобезопасная очередь»
// https://github.com/netology-code/map-diplom
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <queue>
#include <windows.h>

class safe_queue {

	std::queue<std::function<void()>> tasks;	//очередь для хранения задач
	std::mutex mutex;							//для реализации блокировки
	std::condition_variable cv;					//для уведомлений
	

public:
	int getTaskSize() {
		return tasks.size();
	}
	std::mutex& getMutex() {
		return mutex;
	}
	std::condition_variable& getCond() {
		return cv;
	}
	//Метод push записывает в начало очереди новую задачу.
	//При этом захватывает мьютекс, а после окончания операции нотифицируется условная переменная.
	void push(std::function<void()> task) {
		std::unique_lock<std::mutex> lock(mutex);
		tasks.push(task);
		cv.notify_one();
	}
	//Метод pop находится в ожидании, пока не придут уведомление на условную переменную.
	//При нотификации условной переменной данные считываются из очереди.
	std::function<void()> pop() {
		std::unique_lock<std::mutex> lock(mutex);
		cv.wait(lock, [this] { return !tasks.empty(); });
		auto task = tasks.front();
		tasks.pop();
		return task;
	}

};


class thread_pool {
	safe_queue task_queue;
	std::vector<std::thread> threads;
	bool stop;
public:
	thread_pool(size_t num_threads) : stop(false) {
		for (size_t i = 0; i < num_threads; ++i) {
			threads.emplace_back([this]() {
				while (task_queue.getTaskSize() > 0) {
				auto task = task_queue.pop();
				task();
				}
			});
		}
		/*for (size_t i = 0; i < num_threads; ++i) {
			threads.emplace_back(std::thread(&thread_pool::work));
		}*/
	}
	~thread_pool() {
		for (auto& thread : threads) {
			if (thread.joinable()) { thread.join(); }
		}
		stop = true;
	}
	//Метод submit помещает в очередь очередную задачу.
	//В качестве принимаемого аргумента метод может принимать или объект шаблона std::function, или объект шаблона package_task.
	template <typename Func>
	void submit(Func&& func) {
		task_queue.push(std::forward<Func>(func));
	}

	//Метод work выбирает из очереди очередную задачи и исполняет ее.
	//Данный метод передается конструктору потоков для исполнения
	void work() {
		while (task_queue.getTaskSize() > 0) {
			auto task = task_queue.pop();
			task();
		}
	}
};
//Тестовая функция
void test_function(const std::string& name) {
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::cout << "Executing task: " << name << std::endl;
}


int main(int argc, char** argv)
{
	int threads_num = std::thread::hardware_concurrency();
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	thread_pool pool(threads_num);
	//Создадим поток для submit
	std::thread T1 = std::thread([&pool]{for (int i = 0; i < 20; ++i) {
		pool.submit([i] {
			test_function("Task " + std::to_string(i));
			std::this_thread::sleep_for(std::chrono::seconds(1));
			});
	}; });
	T1.join();
	//Создадим поток для work
	std::thread T2 = std::thread([&pool] {pool.work(); });
	T2.join();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "All tasks completed." << std::endl;
	return 0;


}

