#include <iostream>

long long func(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return func(n - 1) + func(n - 2);
}

int main() {
    int n;
    std::cout << "Введите номер числа Фибоначчи (n): ";
    std::cin >> n;

    std::cout << "Результат: " << func(n) << std::endl;

    return 0;
}
// по времени o(2^n) из-за разветвления каждого вызова на два новых
// по памяти o(n) т.к. максимальная грубина стека вызовов пропорциональна n