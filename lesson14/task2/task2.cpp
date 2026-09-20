#include <iostream>
#include <vector>

std::vector <long long> new_arr;

long long fibonachi(int n) {
    if (n <= 0) { return 0; }
    if (n == 1) { return 1; }

    if (new_arr[n] != 0) {
        return new_arr[n];
    }

    new_arr[n] = fibonachi(n - 1) + fibonachi(n - 2);
    return new_arr[n];
}

int main()
{
    setlocale(LC_ALL, "RU");
    int n;
    std::cout << "Введите номер числа Фибоначчи (n): ";

    std::cin >> n;

    if (n < 0) {
        std::cout << "Номер не может быть отрицательным" << std::endl;
        return 1;
    }

    new_arr.resize(n + 1, 0);

    std::cout << "Результат: " << fibonachi(n) << std::endl;
}
