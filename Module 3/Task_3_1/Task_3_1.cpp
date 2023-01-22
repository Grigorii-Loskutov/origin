// Task_3_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//static int counter = 0;
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void merge(int* arr, int q, int size);

void merge_sort(int* arr, int size) {
    if (size > 1) {
        int q = size / 2;
        //std::cout << "Counter = " << counter << "\n";
        //std::cout << "q = " << q; std::cout << " size =  " << size << "\n";
        //std::cout << "Array  = ";
        //counter++;
        //printArray(arr, size);
        merge_sort(&arr[0], q);
        merge_sort(&arr[q], size - q);
        merge(arr, q - 1, size);
    }
}
void merge(int* arr, int q, int size) {

    int n1 = q + 1;
    int n2 = size - q - 1;

    int* L = new int[n1];
    int* M = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[i];
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[q + 1 + j];
    }
    int i = 0, j = 0, k = 0;

     while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] M;
}

int main(int argc, char** argv)
{	
	setlocale(LC_ALL, "Russian");
	int m1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    //int m1[] = { 2,1 };
	int m2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int m3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	unsigned size_m1 = sizeof(m1) / sizeof(m1[0]);
	unsigned size_m2 = sizeof(m2) / sizeof(m2[0]);
	unsigned size_m3 = sizeof(m3) / sizeof(m3[0]);
    std::cout << "Исходный массив:\n ";
    printArray(m1, size_m1);
    merge_sort(m1, size_m1);
    std::cout << "Сортированный массив:\n ";
    printArray(m1, size_m1);
    std::cout << "Исходный массив:\n ";
    printArray(m2, size_m2);
    merge_sort(m2, size_m2);
    std::cout << "Сортированный массив:\n ";
    printArray(m2, size_m2);
    std::cout << "Исходный массив:\n ";
    printArray(m3, size_m3);
    merge_sort(m3, size_m3);
    std::cout << "Сортированный массив:\n ";
    printArray(m3, size_m3);
    
}
