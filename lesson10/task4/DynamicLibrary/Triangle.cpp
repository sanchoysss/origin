#include "Triangle.h"
#include <iostream>


Triangle::Triangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C, const std::string& name)
    : Figure(name), a(side_a), b(side_b), c(side_c), A(angle_A), B(angle_B), C(angle_C) {}

int Triangle::get_a() const { return a; }
int Triangle::get_b() const { return b; }
int Triangle::get_c() const { return c; }
int Triangle::get_A() const { return A; }
int Triangle::get_B() const { return B; }
int Triangle::get_C() const { return C; }

void Triangle::description() const {
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
}
