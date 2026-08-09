#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Parallelogram.h"
#include <string>

class Rhombus : public Parallelogram {
public:
    Rhombus(int side_a, int angle_A, int angle_B, const std::string& name = "Ромб");
};
#endif
