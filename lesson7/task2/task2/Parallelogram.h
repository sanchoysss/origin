#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Quadrilateral.h"
#include <string>

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int side_a, int side_b, int side_c, int side_d, int angle_A, int angle_B, int angle_C, int angle_D, const std::string& name = "Параллелограмм");
};

#endif
