#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"
#include <string>

#ifdef DYNAMICLIBRARY_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif 

class FIGURES_API Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C, const std::string& name = "Треугольник");

    int get_a() const;
    int get_b() const;
    int get_c() const;
    int get_A() const;
    int get_B() const;
    int get_C() const;

    void description() const override;
};

#endif
