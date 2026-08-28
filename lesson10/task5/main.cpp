
#include "main.h"

#include <iostream>
#include <string>

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

void render(const Figure* figure) {
    if (figure != nullptr) {
        cout << figure->get_name() << ":" << endl;
        figure->description();
        cout << endl;
    }
}


int main()
{
    std::setlocale(LC_ALL, ".UTF8");

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


    return 0;
}
