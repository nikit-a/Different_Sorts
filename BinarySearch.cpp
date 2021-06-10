#include <iostream>
#include <vector>

void getNumbers(std::vector<int> &masFirst, std::vector<int> &masSecond) {
    int inputNumberN;
    int inputNumberK;
    std::cin >> inputNumberN >> inputNumberK;
    int inputNumberForMas;
    for (int i = 0; i < inputNumberN; ++i) {
        std::cin >> inputNumberForMas;
        masFirst.push_back(inputNumberForMas);
    }
    for (int i = 0; i < inputNumberK; ++i) {
        std::cin >> inputNumberForMas;
        masSecond.push_back(inputNumberForMas);
    }
}

void searchR(int left, int right, int key, std::vector<int> &masFirst) {
    if (left > right) {
        std::cout << "NO" << std::endl;
        return;
    }
    int m = left + (right - left) / 2;
    if (key == masFirst[m]) {
        std::cout << "YES" << std::endl;
        return;
    }
    if (left == right) {
        std::cout << "NO" << std::endl;
        return;
    }
    if (key < masFirst[m]) {

        return searchR(m + 1, right, key, masFirst);
    }
    if (key > masFirst[m]) {
        return searchR(left, m - 1, key, masFirst);
    }
}

int main() {
    std::vector<int> masFirst;
    std::vector<int> masSecond;
    getNumbers(masFirst, masSecond);

    for (int i : masSecond) {
        searchR(0, masFirst.size() - 1, i, masFirst);
    }
    return 0;
}
