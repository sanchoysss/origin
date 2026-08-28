#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Parallelogram.h"
#include <string>

class Rectangle : public Parallelogram {
public:
    Rectangle(int side_a, int side_b, const std::string& name = "Прямоугольник");
};

#endif