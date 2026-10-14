#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

const double PI = 3.14159265358979323846;

bool readDouble(const wchar_t* prompt, double& value) {
    std::wcout << prompt;
    if (!(std::wcin >> value)) {
        std::wcin.clear();
        std::wcin.ignore(10000, L'\n');
        std::wcerr << L"Ошибка: введено не число!\n";
        return false;
    }
    return true;
}

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    std::wcout << L"Сфера \n";
    std::wcout << L"V = (4/3) * PI * R^3\n";
    std::wcout << L"S = 4 * PI * R^2\n\n";

    double radius;
    if (!readDouble(L"Введите радиус R: ", radius)) return 1;

    if (radius < 0) {
        std::wcerr << L"Ошибка: радиус не может быть отрицательным!\n";
        return 1;
    }

    // double
    double volumeDouble = (4.0 / 3.0) * PI * std::pow(radius, 3);
    double areaDouble   = 4.0 * PI * std::pow(radius, 2);

    // float — демонстрация потери точности
    float radiusFloat = static_cast<float>(radius);
    float piFloat     = static_cast<float>(PI);
    float volumeFloat = (4.0f / 3.0f) * piFloat *
                        static_cast<float>(std::pow(radiusFloat, 3));
    float areaFloat   = 4.0f * piFloat *
                        static_cast<float>(std::pow(radiusFloat, 2));

    // усечение vs округление
    double value     = 3.9999;
    int    truncated = static_cast<int>(value);
    int    rounded   = static_cast<int>(std::round(value));

    // накопление погрешности
    float  sumFloat  = 0.0f;
    double sumDouble = 0.0;
    for (int i = 0; i < 1000; ++i) {
        sumFloat  += 0.1f;
        sumDouble += 0.1;
    }

    std::wcout << std::fixed << std::setprecision(10);

    std::wcout << L"\ndouble \n";
    std::wcout << L"Радиус R  = " << radius       << L"\n";
    std::wcout << L"Объём V   = " << volumeDouble << L"\n";
    std::wcout << L"Площадь S = " << areaDouble   << L"\n";

    std::wcout << L"\nfloat (потеря точности) \n";
    std::wcout << L"V (float) = " << volumeFloat << L"\n";
    std::wcout << L"S (float) = " << areaFloat   << L"\n";
    std::wcout << L"Разница V = "
               << (volumeDouble - static_cast<double>(volumeFloat)) << L"\n";
    std::wcout << L"Разница S = "
               << (areaDouble   - static_cast<double>(areaFloat))   << L"\n";

    std::wcout << L"\nУсечение vs округление \n";
    std::wcout << L"value = " << value << L"\n";
    std::wcout << L"static_cast<int>(value)             = " << truncated
               << L" (усечение)\n";
    std::wcout << L"static_cast<int>(std::round(value)) = " << rounded
               << L" (округление)\n";

    std::wcout << L"\nНакопление погрешности (0.1 x 1000) \n";
    std::wcout << std::setprecision(15);
    std::wcout << L"float  сумма = " << sumFloat  << L"\n";
    std::wcout << L"double сумма = " << sumDouble << L"\n";
    std::wcout << L"Ожидалось    = 100.0\n";

    std::wcout << L"\nГраничные значения \n";
    double testRadii[] = { 0.0, 1.0, -1.0, 1e-6, 1e6 };
    std::wcout << std::setprecision(6);
    for (double r : testRadii) {
        if (r < 0) {
            std::wcout << L"R = " << r << L" -> ошибка\n";
            continue;
        }
        double v = (4.0 / 3.0) * PI * std::pow(r, 3);
        double s = 4.0 * PI * std::pow(r, 2);
        std::wcout << L"R = " << r << L" -> V = " << v << L", S = " << s << L"\n";
    }

    return 0;
}