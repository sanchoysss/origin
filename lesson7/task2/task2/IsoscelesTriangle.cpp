#include "IsoscelesTriangle.h"
#include "Error.h"

IsoscelesTriangle::IsoscelesTriangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C)
    : Triangle(side_a, side_b, side_c, angle_A, angle_B, angle_C, "Равнобедренный треугольник") {

    if (side_a != side_c || angle_A != angle_C) {
        throw Error("Ошибка создания фигуры. Причина: стороны a и c или углы A и C не равны");
    }
}
