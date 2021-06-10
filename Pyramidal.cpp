#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

//Пирамидальная сортировка (она же сортировка кучей) ––
//классический алгоритм который, пожалуй, должен знать любой программист.
//Старая добрая «пирамидка» примечательна тем, что в независимости от
//набора данных у неё одна и та же сложность по времени (причём, очень
//пристойная) – O(n log n). Лучших и вырожденных случаев для неё нет.
//Заготовка *.cpp файла для решения: https://yadi.sk/d/hppBIFQo3RRDmW

using namespace std;

/**
 * Обеспечивает свойство, что значение вершины всегда больше значения детей
 * A[i] >= A[Left(i)] И A[i] >= A[Right(i)]
 * @param mas входной массив с файла
 * @param i индекс массива
 * @param arraySize размер массива
 * @return 0 рекурсивных вызовов не было, другое число - количество рекурсивных вызовов
 */
int heapify(int *mas, int i, int arraySize) {
    // левый ребенок
    int left = 2 * i + 1;
    // правый ребенок
    int right = 2 * i + 2;
    int largest;
    if ((left < arraySize) && (mas[left] > mas[i])) {
        largest = left;
    } else {
        largest = i;
    }
    if ((right < arraySize) && (mas[right] > mas[largest])) {
        largest = right;
    }
    if (largest != i) {
        std::swap(mas[i], mas[largest]);
        // условие на рекурсивный вызов i листика, чтобы не выполнять лишнее действие
        if (largest <= (arraySize - 1) / 2) {
            return heapify(mas, largest, arraySize) + 1;
        }
    }
    return 0;
}

/**
 * Построение кучи и нахождение максимального максимального количества рекурсивных вызовов
 * @param mas входной массив с файла
 * @param arraySize размер массива
 * @return максимальное количество рекурсивных вызовов
 */
int buildHeap(int *mas, int arraySize) {
    int numberMaxCalls = 0;
    for (int i = (arraySize - 1) / 2; i >= 0; --i) {
        int numberCalls = heapify(mas, i, arraySize);
        if (numberCalls > numberMaxCalls) {
            numberMaxCalls = numberCalls;
        }
    }
    return numberMaxCalls;
}

/**
 * Сортировка с помощью кучи
 * @param numbers массив чисел
 * @param array_size размер массива
 */
void heapSort(int *numbers, int array_size) {
    buildHeap(numbers, array_size);
    for (int i = array_size - 1; i > 1; --i) {
        std::swap(numbers[0], numbers[i]);
        array_size--;
        heapify(numbers, 0, array_size);
    }
    // так как осталось 2 вершины и родитель >= ребенку меняем их местами
    swap(numbers[0], numbers[1]);
}

int main() {
    int *brr;
    int n;
    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open()) {
        fin >> n;
        brr = new int[n];
        for (int i = 0; i < n; i++) {
            fin >> brr[i];
        }
        fin.close();
    }
    heapSort(brr, n);
    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = 0; i < n; i++)
        fout << brr[i] << " ";

    fout.close();
    delete[] brr;
    return 0;
}