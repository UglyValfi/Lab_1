#include <iostream>
#include <vector>
#include <cmath>

int main() {
    #if defined(_WIN32) || defined(_WIN64)
    std::system("chcp 65001 > nul");
    #endif

    int n;
    std::cout << "=== Робота з одновимірним масивом ===" << std::endl;
    std::cout << "Введіть кількість елементів масиву: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Помилка: розмір масиву має бути більшим за 0!" << std::endl;
        return 1;
    }

    std::vector<double> arr(n);
    std::cout << "Введіть " << n << " елементів масиву через пробіл або Enter:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    double sumNegative = 0.0;
    bool hasNegative = false;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            sumNegative += arr[i];
            hasNegative = true;
        }
    }

    double maxVal = arr[0];
    double minVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    double productMaxMin = maxVal * minVal;

    std::cout << "\n--- РЕЗУЛЬТАТИ ---" << std::endl;
    if (hasNegative) {
        std::cout << "1. Сума від'ємних елементів: " << sumNegative << std::endl;
    } else {
        std::cout << "1. У масиві немає від'ємних елементів." << std::endl;
    }
    
    std::cout << "2. Найбільший елемент: " << maxVal << std::endl;
    std::cout << "2. Найменший елемент: " << minVal << std::endl;
    std::cout << "2. Добуток найбільшого та найменшого елементів: " << productMaxMin << std::endl;

    return 0;
}