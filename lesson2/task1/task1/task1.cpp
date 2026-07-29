#include <iostream>

class Calculator {
private:
    double num1;
    double num2;
public:
    double add() {
        return num1 + num2;
    }
    double multiply() {
        return num1 * num2;
    }
    double subtract_1_2() {
        return num2 - num1;
    }
    double subtract_2_1() {
        return num1 - num2;
    }
    double divide_1_2() {
        return num1 / num2;
    }
    double divide_2_1() {
        return num2 / num1;
    }

    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        } return false;
    }

    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        } return false;
    }

};

int main()
{
    std::setlocale(LC_ALL, "Russian");
    Calculator calculator;

    while (true) {
        double input1, input2;

        std::cout << "Введите num1: ";
        std::cin >> input1;

        while (!calculator.set_num1(input1)) {
            std::cout << "Неверный ввод!\nВведите num1: ";
            std::cin >> input1;
        }
       

        std::cout << "Введите num2: ";
        std::cin >> input2;

        while (!calculator.set_num2(input2)) {
            std::cout << "Неверный ввод!\nВведите num2: ";
            std::cin >> input2;
        }

        std::cout << "num1 + num2 = " << calculator.add() << std::endl;
        std::cout << "num1 - num2 = " << calculator.subtract_2_1() << std::endl;
        std::cout << "num2 - num1 = " << calculator.subtract_1_2() << std::endl;
        std::cout << "num1 * num2 = " << calculator.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calculator.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calculator.divide_2_1() << std::endl;
    }
    return 0;
}
