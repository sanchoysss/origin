#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Parallelogram.h"
#include <string>

#ifdef DYNAMICLIBRARY_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif 

class FIGURES_API Rhombus : public Parallelogram {
public:
    Rhombus(int side_a, int angle_A, int angle_B, const std::string& name = "Ромб");
};
#endif
