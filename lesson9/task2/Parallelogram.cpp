#include "Parallelogram.h"

Parallelogram::Parallelogram(int  side_a, int side_b, int angle_A, int angle_B, const std::string& name)
    : Quadrilateral(side_a, side_b, side_a, side_b, angle_A, angle_B, angle_A, angle_B, name) {
}