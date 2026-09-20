#include <iostream>
#include <iomanip>   // для setprecision

int main() {
    double a, b, c;   // длина, ширина, высота
    double V, S;      // объём и площадь поверхности
    std::cout << "Введите длину параллелепипеда: ";
    std::cin >> a;
    // проверка: введено ли число
    if (std::cin.fail()) {
        std::cout << "Ошибка: нужно было ввести число!\n";
        return 1;
    }
    std::cout << "Введите ширину: ";
    std::cin >> b;
    if (std::cin.fail()) {
        std::cout << "Ошибка: нужно было ввести число!\n";
        return 1;
    }
    std::cout << "Введите высоту: ";
    std::cin >> c;
    if (std::cin.fail()) {
        std::cout << "Ошибка: нужно было ввести число!\n";
        return 1;
    }
    // проверка на отрицательные и нулевые значения
    if (a <= 0 || b <= 0 || c <= 0) {
        std::cout << "Ошибка: размеры должны быть положительными!\n";
        return 1;
    }
    // объём
    V = a * b * c;
    // площадь поверхности
    S = 2 * (a * b + a * c + b * c);
    // вывод результатов
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "\nДлина: " << a << "\n";
    std::cout << "Ширина: " << b << "\n";
    std::cout << "Высота: " << c << "\n";
    std::cout << "Объём: " << V << "\n";
    std::cout << "Площадь поверхности: " << S << "\n";
    return 0;
}