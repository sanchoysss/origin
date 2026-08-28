#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Triangle.h"

#ifdef DYNAMICLIBRARY_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif 

class FIGURES_API RightTriangle : public Triangle {
public:
    RightTriangle(int side_a, int side_b, int side_c, int angle_A, int angle_B);
};

#endif 

