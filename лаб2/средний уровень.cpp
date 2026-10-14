#include <iostream>
#include <iomanip>
#include <limits>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // double — стороны могут быть дробными, int потерял бы точность
    double length, width;

    std::wcout << L"Прямоугольник\n";
    std::wcout << L"Введите длину: ";
    if (!(std::wcin >> length)) {
        std::wcin.clear();
        std::wcin.ignore(10000, L'\n');
        std::wcerr << L"Ошибка ввода!\n";
        return 1;
    }

    std::wcout << L"Введите ширину: ";
    if (!(std::wcin >> width)) {
        std::wcin.clear();
        std::wcin.ignore(10000, L'\n');
        std::wcerr << L"Ошибка ввода!\n";
        return 1;
    }

    if (length < 0 || width < 0) {
        std::wcerr << L"Ошибка: стороны не могут быть отрицательными!\n";
        return 1;
    }

    double perimeter = 2.0 * (length + width);
    double area      = length * width;

    // static_cast — сравнение с целочисленным результатом
    int lengthInt = static_cast<int>(length);
    int widthInt  = static_cast<int>(width);
    int areaInt   = lengthInt * widthInt;

    std::wcout << std::fixed << std::setprecision(3);
    std::wcout << L"\nДлина    = " << length    << L"\n";
    std::wcout << L"Ширина   = " << width     << L"\n";
    std::wcout << L"Периметр = " << perimeter << L"\n";
    std::wcout << L"Площадь  = " << area      << L"\n";

    std::wcout << L"\nЧерез int (static_cast):\n";
    std::wcout << L"Площадь  = " << areaInt   << L" (потеря точности)\n";

    return 0;
}