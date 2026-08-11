#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Quadrilateral.h"
#include <string>

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int side_a, int side_b, int angle_A, int angle_B, const std::string& name = "Параллелограмм");
};

#endif
