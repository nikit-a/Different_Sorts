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
    for (int i = 1; i < mas.size(); ++i) {
        int lf = 0;
        int rg = i - 1;
        int m = (lf + rg) / 2;
        while (lf != m) {
            if (mas[m] > mas[i]) {
                rg = m - 1;
            } else {
                lf = m;
            }
            m = (lf + rg) / 2;
        }
        if (mas[lf] <= mas[i]) {
            if (mas[rg] <= mas[i]) {
                lf = rg + 1;
            } else {
                lf = rg;
            }
        }
        int k = i;
        int p = mas[i];
        while (k > lf) {
            mas[k] = mas[k - 1];
            k = k - 1;
            numNoExchange++;
        }
        mas[lf] = p;
    }
    for (int number : mas) {
        std::cout << number;
        std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << numNoExchange;
    return 0;
}
