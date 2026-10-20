#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    #if defined(_WIN32) || defined(_WIN64)
    std::system("chcp 65001 > nul");
    #endif

    double a, b, c;
    double x_start, x_end, dx;

    std::cout << "=== Табулювання функції F(x) ===" << std::endl;
    std::cout << "Введіть параметр a: ";
    std::cin >> a;
    std::cout << "Введіть параметр b: ";
    std::cin >> b;
    std::cout << "Введіть параметр c: ";
    std::cin >> c;

    std::cout << "Введіть початок інтервалу (X_start): ";
    std::cin >> x_start;
    std::cout << "Введіть кінець інтервалу (X_end): ";
    std::cin >> x_end;
    std::cout << "Введіть крок (DX): ";
    std::cin >> dx;

    if (dx <= 0 && x_start <= x_end) {
        std::cout << "Помилка: крок DX має бути більшим за 0!" << std::endl;
        return 1;
    }

    double sumF = 0.0;
    int count = 0;

    std::cout << "\n-----------------------------------" << std::endl;
    std::cout << std::setw(10) << "X" << " | " << std::setw(15) << "F(X)" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    double x = x_start;
    for (int i = 0; ; ++i) {
        if (x > x_end + 1e-9) break;

        double F = 0.0;
        bool isValid = true;

        if (x < 0 && b != 0) {
            F = a * x * x + b;
        } 
        else if (x > 0 && b == 0) {
            if (std::abs(x - c) < 1e-9) {
                isValid = false;
            } else {
                F = (x - a) / (x - c);
            }
        } 
        else {
            if (std::abs(c) < 1e-9) {
                isValid = false;
            } else {
                F = x / c;
            }
        }

        if (isValid) {
            std::cout << std::setw(10) << std::fixed << std::setprecision(4) << x 
                      << " | " << std::setw(15) << std::fixed << std::setprecision(4) << F << std::endl;
            sumF += F;
            count++;
        } else {
            std::cout << std::setw(10) << std::fixed << std::setprecision(4) << x 
                      << " | " << std::setw(15) << "Помилка (діл. на 0)" << std::endl;
        }

        x = x_start + (i + 1) * dx;
    }

    std::cout << "-----------------------------------" << std::endl;

    if (count > 0) {
        double averageF = sumF / count;
        std::cout << "\nСереднє значення функції F на проміжку: " << averageF << std::endl;
    } else {
        std::cout << "\nНемає коректно обчислених значень функції для розрахунку середнього." << std::endl;
    }

    return 0;
}