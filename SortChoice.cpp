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
    int numExchange = 0;
    for (int i = 0; i < mas.size() - 1; i++) {
        int min = i;
        int flag = false;
        for (int j = i + 1; j < mas.size(); j++) {
            if (mas[j] < mas[min]) {
                min = j;
                flag = true;
            }
        }
        if (flag) {
            std::swap(mas[i], mas[min]);
            numExchange++;
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
