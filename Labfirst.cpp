#include <iostream>
#include <cmath>

int main() {
    #if defined(_WIN32) || defined(_WIN64)
    std::system("chcp 65001 > nul");
    #endif

    double A;
    std::cout << "Введіть значення числа A: ";
    std::cin >> A;

    double rho = 0.0;

    if (A > -0.5) {
        double rootVal = std::pow(A + 1.0, 1.0 / 5.0); 
        double tanVal = std::tan(std::exp(A + 1.0));    
        rho = rootVal - (tanVal * tanVal);
    } 
    else if (A >= -1.0 && A <= -0.5) {
        double logVal = std::log(std::abs(A)) + std::exp(A);
        rho = std::abs(logVal) + std::pow(10.0, -4.0);
    } 
    else {
        double underSqrt = A + M_PI;
        if (underSqrt < 0) {
            std::cerr << "Помилка: підкореневий вираз (x + pi) є від'ємним!" << std::endl;
            return 1;
        }
        double cosVal = std::cos(std::sqrt(underSqrt));
        rho = cosVal * cosVal;
    }

    std::cout << "Значення функції rho для A = " << A << " дорівнює: " << rho << std::endl;

    return 0;
}