// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

struct Info {
    int numberAcc;
    std::string name;
    float balance;
};

void change(Info& account, float newBalance) {
    account.balance = newBalance;

}

int main()
{
    setlocale(LC_ALL, "Russian");
    Info User;

    std::cout << "Введите номер счёта: ";
    std::cin >> User.numberAcc;

    std::cout << "Введите имя владельца: ";
    std::cin >> User.name;

    std::cout << "Введите баланс: ";
    std::cin >> User.balance;

    float newBalance = 0.0;
    std::cout << "Введите новый баланс: ";
    std::cin >> newBalance;

    change(User, newBalance);

    std::cout << "Ваш счёт: " << User.name << ", " << User.numberAcc << ", " << User.balance << std::endl;

    return 0;
}

