#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Parallelogram.h"
#include <string>

#ifdef DYNAMICLIBRARY_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif 

class FIGURES_API Rectangle : public Parallelogram {
public:
    Rectangle(int side_a, int side_b, const std::string& name = "Прямоугольник");
};

#endif