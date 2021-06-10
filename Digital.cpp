#include "ReadWriter.h"

using namespace std;


union Number {
    int number;
    uint8_t byte[4];
};

/**
 * Получение количества разрядов максимального числа
 * @param inputMas массив из файла
 * @param size размер массива из файла
 * @return количества разрядов максимального числа
 */
int getDigitsMaxNumber(const int *inputMas, int size) {
    int maxElementMasA = -1;
    // находим максимальный элемент в массиве
    for (int i = 0; i < size; ++i) {
        if (maxElementMasA < inputMas[i]) {
            maxElementMasA = inputMas[i];
        }
    }
    Number unMax = {maxElementMasA};
    int digitsMaxNumber = 0;
    // находим количество разрядов максимального числа
    for (int i = 0; i < 3; ++i) {
        if (unMax.byte[i] != 0) {
            digitsMaxNumber++;
        } else {
            break;
        }
    }
    return digitsMaxNumber;
}

/**
 * Цифровая сортировка массива
 * @param numbers массив из файла
 * @param array_size размер массива из файла
 */
void countingSort(int *numbers, int array_size) {
    // обработка случая пустового массива
    if (array_size > 0) {
        int digitsMaxNumber = getDigitsMaxNumber(numbers, array_size);
        int sizeMasC = 256;
        int *masC;
        // проходим по каждой цифре чисел, начиная со старшего
        for (int i = 0; i < digitsMaxNumber; ++i) {
            // обнуляем вспомогательный массив
            masC = new int[sizeMasC]{0};
            // считаем количество элементов массива А равных j
            for (int j = 0; j < array_size; ++j) {
                Number num = {numbers[j]};
                masC[num.byte[i]] += 1;
            }
            // находим частичные суммы
            for (int j = 1; j < sizeMasC; ++j) {
                masC[j] += masC[j - 1];
            }
            int *masB;
            masB = new int[array_size];
            // получаем сортированный массив B
            for (int j = array_size - 1; j >= 0; --j) {
                Number num = {numbers[j]};
                masB[masC[num.byte[i]] - 1] = numbers[j];
                masC[num.byte[i]] -= 1;
            }
            // заменяем элементы изначального массива на сортированный порядок
            for (int j = 0; j < array_size; ++j) {
                numbers[j] = masB[j];
            }
            // освобождаем память от masB
            delete[] masB;
            // освобождаем память от masC
            delete[] masC;

        }
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
    //Запуск сортировки radix sort, ответ в том же массиве (brr)
    countingSort(brr, n);
    //Запись в файл
    rw.writeArray(brr, n);
    //освобождаем память
    delete[] brr;
    return 0;
}
