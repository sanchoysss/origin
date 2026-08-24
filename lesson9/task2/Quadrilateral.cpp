#include "Quadrilateral.h"
#include <iostream>


Quadrilateral::Quadrilateral(int side_a, int side_b, int side_c, int side_d, int angle_A, int angle_B, int angle_C, int angle_D, const std::string& name)
    : Figure(name), a(side_a), b(side_b), c(side_c), d(side_d), A(angle_A), B(angle_B), C(angle_C), D(angle_D) {
}

int Quadrilateral::get_a() const { return a; }
int Quadrilateral::get_b() const { return b; }
int Quadrilateral::get_c() const { return c; }
int Quadrilateral::get_d() const { return d; }
int Quadrilateral::get_A() const { return A; }
int Quadrilateral::get_B() const { return B; }
int Quadrilateral::get_C() const { return C; }
int Quadrilateral::get_D() const { return D; }

void Quadrilateral::description() const {
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
}
