#include <iostream>
#include <vector>

void getNumbers(std::vector<int> &mas) {
    int inputNumberN;
    std::cin >> inputNumberN;
    int inputNumberForMas;
    for (int i = 0; i < inputNumberN; ++i) {
        std::cin >> inputNumberForMas;
        mas.push_back(inputNumberForMas);
    }

}

int main() {
    std::vector<int> mas;
    getNumbers(mas);
    bool t = false;
    int numExchange = 0;
    for (int i = 0; i < mas.size() && !t; ++i) {
        t = true;
        for (int j = 0; j < mas.size() - (i + 1); ++j) {
            if (mas[j] > mas[j + 1]) {
                std::swap(mas[j], mas[j + 1]);
                numExchange++;
                t = false;
            }
        }
    }

    for (int number : mas) {
        std::cout << number;
        std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << numExchange;
    return 0;
}
