#include "RightTriangle.h"

RightTriangle::RightTriangle(int side_a, int side_b, int side_c, int angle_A, int angle_B)
    : Triangle(side_a, side_b, side_c, angle_A, angle_B, 90, "Прямоугольный треугольник") {
}

