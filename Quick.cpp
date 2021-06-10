#include <iostream>
#include <fstream>


/*
 Реализовать сортировку Хоара (быструю, quicksort)
по неубыванию для заданного целочисленного массива N элементов
с выбором в качестве опорного среднего элемента обрабатываемой части массива.
Решить данную задачу требуется по классической схеме Хоара: с двумя индексами и массив делится на 2 части.
Определить количество рекурсивных вызовов.
ВВОД:
 3
33 22 11

 */

class ReadWriter {

private:
    std::fstream fin;
    std::fstream fout;

public:
    ~ReadWriter() {
        fin.close();
        fout.close();
    }

    ReadWriter() {
        fin.open("input.txt", std::ios::in);
        fout.open("output.txt", std::ios::out);
    }

    /**
     * Чтение числа элементов массива из файла
     * @return количество дронов
     */
    int readInt() {
        if (!fin.is_open()) {
            throw std::ios_base::failure("file not open");
        }
        int n = 0;
        fin >> n;
        return n;
    }

    /**
     * Чтение массива чисел из файла
     * @param arrNumbers массив
     * @param length длинна массива
     */
    void readArray(int *arrNumbers, int length) {
        if (!fin.is_open()) {
            throw std::ios_base::failure("file not open");
        }
        for (int i = 0; i < length; i++)
            fin >> arrNumbers[i];
    }

    /**
     * Запись в файл количества рекурсивных вызовов и отсортированный массив
     * @param arrNumbers отсортированный массив
     * @param n размер массива
     * @param numberCalls количество рекурсивных вызовов
     */
    void writeArray(int *arrNumbers, int n, int numberCalls) {
        if (!fout.is_open()) {
            throw std::ios_base::failure("file not open");
        }
        fout << numberCalls << "\n";
        for (int i = 0; i < n - 1; i++) {
            fout << arrNumbers[i] << " ";
        }
        fout << arrNumbers[n - 1];
    }
};

/**
 * Быстрая сортировка
 * @param mas входной массив
 * @param first индекс начала
 * @param last индекса конца
 * @param numberCall количество рекурсивных вызовов
 */
void quickSort(int *mas, int first, int last, int &numberCall) {
    int i = first;
    int j = last;
    int k = (i + j) / 2;
    int pivot = mas[k];
    do {
        while (mas[i] < pivot) {
            i++;
        }
        while (mas[j] > pivot) {
            j--;
        }
        if (i <= j) {
            // свапаем так как нашли элемент >= выбранному слева и <= выбранному справа
            std::swap(mas[i], mas[j]);
            i++;
            j--;
        }
        // пока один индекс не прошел другой
    } while (i <= j);
    if (first < j) {
        numberCall++;
        // вызываем рекурсивно на левой части массива
        quickSort(mas, first, j, numberCall);
    }
    if (last > i) {
        numberCall++;
        // вызываем рекурсивно на правой части массива
        quickSort(mas, i, last, numberCall);
    }
}

int main() {
    ReadWriter rw;
    // чтение размера массива с файла
    int sizeMas = rw.readInt();
    int *numbers;
    numbers = new int[sizeMas];
    // чтение массива с файла
    rw.readArray(numbers, sizeMas);
    int numberCallFunc = 0;
    // вызов сортировки
    quickSort(numbers, 0, sizeMas - 1, numberCallFunc);
    // запись в файл
    rw.writeArray(numbers, sizeMas, numberCallFunc);
    // освобождаем ресурсы
    delete[] numbers;
    return 0;
}