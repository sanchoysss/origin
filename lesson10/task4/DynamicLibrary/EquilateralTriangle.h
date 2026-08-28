#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

#include "Triangle.h"

#ifdef DYNAMICLIBRARY_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif // DYNAMICLIBRARY_EXPORTS


class FIGURES_API EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side_a);
};

#endif
