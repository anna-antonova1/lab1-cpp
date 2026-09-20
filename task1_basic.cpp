#include <iostream> 
int main() {
    double side = 0.0;
    std::cout << "=== Калькулятор периметра квадрата ===\n";
    std::cout << "Введите сторону квадрата: ";
    // Считывание значения
    std::cin >> side;
    // Вычисление периметра: P = 4 * a
    double perimeter = 4.0 * side;
    // Вывод результата
    std::cout << "Периметр квадрата = " << perimeter << std::endl;
    return 0; 
}