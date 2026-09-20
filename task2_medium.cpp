#include <iostream>
#include <iomanip>   // Для std::fixed и std::setprecision
int main() {
    double side = 0.0;
    std::cout << "=== Квадрат: периметр и площадь ===\n";
    std::cout << "Введите сторону квадрата: ";
     // Считывание значения
    std::cin >> side;
     // Вычисления
    double perimeter = 4.0 * side;      // P = 4 * a
    double area = side * side;          // S = a * a
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Периметр квадрата: " << perimeter << "\n";
    std::cout << "Площадь квадрата:  " << area << "\n";

    return 0;
}