#include <iostream>
#include "math_functions.h"

int main()
{
    std::setlocale(LC_ALL, "RU");
    double num1, num2;
    int operation;

    std::cout << "Введите первое число: ";
    std::cin >> num1;

    std::cout << "Введите второе число: ";
    std::cin >> num2;

    std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> operation;

    switch (operation) {
    case 1:
        std::cout<< num1 << " + " << num2 << " = " << add(num1, num2) << std::endl;
        break;
    case 2:
        std::cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << std::endl;
        break;
    case 3:
        std::cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << std::endl;
        break;
    case 4:
        if (num2 == 0) {
            std::cout << "Ошибка деления на 0" << std::endl;
        }
        else {
            std::cout << num1 << " / " << num2 << " = " << divide(num1, num2) << std::endl;
        }
        break;
    case 5:
        std::cout << num1 << " в степени " << num2 << " = " << power(num1, num2) << std::endl;
        break;
    default:
        std::cout << "Выберите верную операцию" << std::endl;
        break;
    }
    return 0;
}
