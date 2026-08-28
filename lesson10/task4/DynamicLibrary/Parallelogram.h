#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Quadrilateral.h"
#include <string>

#ifdef DYNAMICLIBRARY_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif 

class FIGURES_API Parallelogram : public Quadrilateral {
public:
    Parallelogram(int side_a, int side_b, int angle_A, int angle_B, const std::string& name = "Параллелограмм");
};

#endif
