#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;

// Функция сортировки подсчетом
void countingSort(int *numbers, int array_size) {
    // обработка случая пустового массива
    if (array_size > 0) {
        int minElementMasA = 1000001;
        int maxElementMasA = -1;
        // Находим максимальный и минимальный элементы в массиве
        for (int i = 0; i < array_size; ++i) {
            if (maxElementMasA < numbers[i]) {
                maxElementMasA = numbers[i];
            }
            if (minElementMasA > numbers[i]) {
                minElementMasA = numbers[i];
            }
        }
        int sizeMasC = maxElementMasA - minElementMasA + 1;
        int *masC;
        masC = new int[sizeMasC];
        // Считаем количество элементов массива А равных i
        for (int i = 0; i < array_size; ++i) {
            masC[numbers[i] - minElementMasA] += 1;
        }
        // Находим частичные суммы
        for (int i = 1; i < sizeMasC; ++i) {
            masC[i] += masC[i - 1];
        }
        int *masB;
        masB = new int[array_size];
        // Получаем сортированный массив B
        for (int i = array_size - 1; i >= 0; --i) {
            masB[masC[numbers[i] - minElementMasA] - 1] = numbers[i];
            masC[numbers[i] - minElementMasA] -= 1;

        }
        // заменяем элементы изначального массива на сортированный порядок
        for (int i = 0; i < array_size; ++i) {
            numbers[i] = masB[i];
        }
        // Освобождаем память от masB
        delete[] masB;
        // Освобождаем память от masC
        delete[] masC;
    }
}

int main() {
    //Объект для работы с файлами
    ReadWriter rw;
    int *brr;
    int n;
    //Ввод из файла
    n = rw.readInt();
    brr = new int[n];
    rw.readArray(brr, n);
    //Запуск сортировки, ответ в том же массиве (brr)
    countingSort(brr, n);
    //Запись в файл
    rw.writeArray(brr, n);
    //освобождаем память
    delete[] brr;
    return 0;
}