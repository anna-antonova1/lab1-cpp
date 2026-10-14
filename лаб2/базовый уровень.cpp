#include <iostream>    
#include <iomanip>     
#include <limits>      
#include <windows.h>   
#include <io.h>        
#include <fcntl.h>     
int main() {

    // настройка консоли на русский язык

    // Переключаем стандартный ВЫВОД (stdout) в режим Unicode.
    _setmode(_fileno(stdout), _O_U16TEXT);

    // То же самое для стандартного ВВОДА (stdin), чтобы wcin корректно читал данные.
    _setmode(_fileno(stdin), _O_U16TEXT);

    // Устанавливаем кодовую страницу консоли на UTF-8 (65001), это нужно для правильного отображения кириллицы.
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // объявление переменных
    double side;       // сторона квадрата (дробная — поэтому double)
    double perimeter;  // периметр = 4 * side

    // Префикс L перед строкой делает её широкой (wide string), wcout умеет работать только с такими строками.
    std::wcout << L"Периметр квадрата \n";
    std::wcout << L"Введите сторону квадрата a: ";

    // === ВВОД ЧИСЛА ===
    // wcin — широкий аналог cin, читает в double.
    std::wcin >> side;

    // === ПРОВЕРКА: ВВЕДЕНО ЛИ ЧИСЛО ===
    // Если пользователь ввёл буквы — поток уйдёт в состояние ошибки.
    if (!std::wcin) {
        std::wcin.clear();                              // сбрасываем флаг ошибки
        std::wcin.ignore(10000, L'\n');                 // очищаем буфер ввода
        std::wcerr << L"Ошибка: введено не число!\n";   // сообщение об ошибке
        return 1;                                       // выход с кодом ошибки
    }

    //проверка не отрицательная ли строка
    if (side < 0) {
        std::wcerr << L"Ошибка: сторона не может быть отрицательной!\n";
        return 1;
    }

    // вычисление периметра
    perimeter = 4.0 * side;

    // форматирование вывода
    // fixed — вывод в обычном виде (не экспонентой), setprecision(3) — 3 знака после запятой.
    std::wcout << std::fixed << std::setprecision(3);

    // вывод результата
    std::wcout << L"\nСторона a = " << side << L"\n";
    std::wcout << L"Периметр P = 4 * a = " << perimeter << L"\n";

    return 0;
}