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
    int numNoExchange = 0;
    bool noExchange;
    for (int i = 1; i < mas.size(); ++i) {
        noExchange = true;
        int b = mas[i];
        int j = i - 1;
        for (; b < mas[j] && j >= 0; --j) {
            mas[j + 1] = mas[j];
            noExchange = false;
        }
        if (noExchange) numNoExchange++;
        mas[j + 1] = b;
    }
    for (int number : mas) {
        std::cout << number;
        std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << numNoExchange;
    return 0;
}
