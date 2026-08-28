#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"

#ifdef DYNAMICLIBRARY_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif 

class FIGURES_API Square : public Rectangle {
public:
    Square(int side_a);
};

#endif