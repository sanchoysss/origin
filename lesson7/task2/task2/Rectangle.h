#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Parallelogram.h"
#include <string>

class Rectangle : public Parallelogram {
public:
    Rectangle(int side_a, int side_b, int side_c, int side_d, int angle_A, int angle_B, int angle_C, int angle_D, const std::string& name = "Прямоугольник");
};

#endif