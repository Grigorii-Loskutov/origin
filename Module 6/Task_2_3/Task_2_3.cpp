// Task_2_3.cpp :«Защищенный обмен данными»
// https://github.com/netology-code/map-homeworks/tree/main/02

#include <iostream>
#include <mutex>
#include <utility>
#include <windows.h>

class Data {
public:
    explicit Data(int value) : data(value) {}

    int getData() const {
        return data;
    }

    void setData(int value) {
        data = value;
    }

    std::mutex& getMutex() {
        return mutex;
    }

private:
    int data;
    std::mutex mutex;
};

void swap(Data& a, Data& b) {
    // Вариант с использованием lock
    std::lock(a.getMutex(), b.getMutex());
    std::lock_guard<std::mutex> lockA(a.getMutex(), std::adopt_lock);
    std::lock_guard<std::mutex> lockB(b.getMutex(), std::adopt_lock);


    // Вариант с использованием scoped_lock
    //std::scoped_lock lock(a.getMutex(), b.getMutex());
   

    // Вариант с использованием unique_lock
    /* std::unique_lock<std::mutex> lockA(a.getMutex(), std::defer_lock);
     std::unique_lock<std::mutex> lockB(b.getMutex(), std::defer_lock);
     std::lock(lockA, lockB);*/
     

     // Обмен данными
     int temp = a.getData();
     a.setData(b.getData());
     b.setData(temp);
}


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    Data data1(1);
    Data data2(2);

    std::cout << "Before swap: data1 = " << data1.getData() << ", data2 = " << data2.getData() << std::endl;

    swap(data1, data2);

    std::cout << "After swap: data1 = " << data1.getData() << ", data2 = " << data2.getData() << std::endl;

    return 0;
  
}