#include <iostream>
#include <iomanip>

int main() {
    #if defined(_WIN32) || defined(_WIN64)
    std::system("chcp 65001 > nul");
    #endif

    const int N = 12; 
    double matrix[N][N];

    std::cout << "=== Робота з двовимірним масивом (матриця 12x12) ===" << std::endl;
    std::cout << "Бажаєте заповнити матрицю випадковими числами чи вручну?" << std::endl;
    std::cout << "1 - Випадкові числа, 2 - Вручну: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                matrix[i][j] = -10 + rand() % 21; 
            }
        }
    } else {
        std::cout << "Введіть елементи матриці 12x12 (" << N * N << " чисел):\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cin >> matrix[i][j];
            }
        }
    }

    std::cout << "\nВихідна матриця:" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j >= i) { 
                matrix[i][j] = 0.0;
            }
        }
    }

    std::cout << "\nМатриця після заміни (нули на головній діагоналі та вище):" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}