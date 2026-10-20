#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define N 25 

int main() {

    #if defined(_WIN32) || defined(_WIN64)
    std::system("chcp 65001 > nul");
    #endif

    std::srand(std::time(0));

    int masiv[N];

    for (int i = 0; i < N; ++i) {
        masiv[i] = -15 + std::rand() % 31;
    }

    std::cout << "=== Згенерований масив (25 елементів) ===" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << masiv[i] << "\t";
        if ((i + 1) % 5 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    int sumOddIndex = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 != 0) { 
            sumOddIndex += masiv[i];
        }
    }

    int maxIndex = 0;
    int minIndex = 0;
    for (int i = 1; i < N; ++i) {
        if (masiv[i] > masiv[maxIndex]) {
            maxIndex = i;
        }
        if (masiv[i] < masiv[minIndex]) {
            minIndex = i;
        }
    }

    int startIdx = (maxIndex < minIndex) ? maxIndex : minIndex;
    int endIdx = (maxIndex > minIndex) ? maxIndex : minIndex;
    int countBetween = endIdx - startIdx - 1; 

    std::cout << "\n--- РЕЗУЛЬТАТИ ОБЧИСЛЕНЬ ---" << std::endl;
    std::cout << "1. Сума елементів з непарними номерами: " << sumOddIndex << std::endl;
    std::cout << "2. Найбільший елемент: " << masiv[maxIndex] << " (позиція/індекс " << maxIndex << ")" << std::endl;
    std::cout << "2. Найменший елемент: " << masiv[minIndex] << " (позиція/індекс " << minIndex << ")" << std::endl;
    std::cout << "2. Кількість елементів між ними: " << countBetween << std::endl;

    return 0;
}