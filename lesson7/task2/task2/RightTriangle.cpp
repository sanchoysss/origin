#include "RightTriangle.h"
#include "Error.h"

RightTriangle::RightTriangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C)
    : Triangle(side_a, side_b, side_c, angle_A, angle_B, angle_C, "Прямоугольный треугольник") {

    if (angle_C != 90) {
        throw Error("Ошибка создания фигуры. Причина: угол C не равен 90");
    }
}
