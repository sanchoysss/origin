#include "tasks.h"
#include <iostream>
#include <string>

#include "math_functions.h"
#include "counter.h"
#include "Figure.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrilateral.h"
#include "Parallelogram.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Square.h"

using namespace std;

void run_task1() {

    double num1, num2;
    int operation;

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;
    cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    cin >> operation;

    switch (operation) {
    case 1:
        cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
        break;
    case 2:
        cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
        break;
    case 3:
        cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
        break;
    case 4:
        if (num2 == 0) {
            cout << "Ошибка деления на 0" << endl;
        }
        else {
            cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
        }
        break;
    case 5:
        cout << num1 << " в степени " << num2 << " = " << power(num1, num2) << endl;
        break;
    default:
        cout << "Выберите верную операцию" << endl;
        break;
    }
    cout << endl;
}

void run_task2() {

    string choice;
    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    cin >> choice;

    int user_num;
    Counter counter;
    if (choice == "да") {
        cout << "Введите начальное значение счётчика: ";
        cin >> user_num;
        counter = Counter(user_num);
    }
    else {
        counter = Counter();
    }

    char command;
    bool com_running = true;
    while (com_running) {
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
        cin >> command;

        switch (command) {
        case '+':
            counter.add();
            break;
        case '-':
            counter.subtract();
            break;
        case '=':
            cout << counter.get_current() << endl;
            break;
        case 'x':
            cout << "До свидания!" << endl;
            com_running = false;
            break;
        default:
            cout << "Неверная команда" << endl;
            break;
        }
    }
    cout << endl;
}

void render(const Figure* figure) {
    if (figure != nullptr) {
        cout << figure->get_name() << ":" << endl;
        figure->description();
        cout << endl;
    }
}

void run_task3() {

    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    
    render(&triangle);
    render(&right_triangle);
    render(&isosceles_triangle);
    render(&equilateral_triangle);

    render(&quadrilateral);
    render(&rectangle);
    render(&square);
    render(&parallelogram);
    render(&rhombus);
}