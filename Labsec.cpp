#include <iostream>
#include <cmath>

int main() {
    #if defined(_WIN32) || defined(_WIN64)
    std::system("chcp 65001 > nul");
    #endif

    double x, a;

    std::cout << "=== Обчислення виразу y = sqrt(x - 4) / sqrt(3 * a^3) ===" << std::endl;
    
    std::cout << "Введіть значення x: ";
    std::cin >> x;

    std::cout << "Введіть значення a: ";
    std::cin >> a;

    if (x < 4.0) {
        std::cout << "Помилка: x має бути більшим або дорівнювати 4 (x >= 4), оскільки вираз під коренем в чисельнику від'ємний!" << std::endl;
        return 1;
    }

    if (a <= 0.0) {
        std::cout << "Помилка: a має бути строго більшим за 0 (a > 0), інакше знаменник дорівнює 0 або містить корінь з від'ємного числа!" << std::endl;
        return 1;
    }

    double numerator = std::sqrt(x - 4.0);           
    double denominator = std::sqrt(3.0 * std::pow(a, 3.0));

    double y = numerator / denominator;

    std::cout << "\nРезультат:" << std::endl;
    std::cout << "y = " << y << std::endl;

    return 0;
}