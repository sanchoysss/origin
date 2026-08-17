#include "Rectangle.h"
#include "Error.h"

Rectangle::Rectangle(int side_a, int side_b, int side_c, int side_d, int angle_A, int angle_B, int angle_C, int angle_D, const std::string& name) :
    Parallelogram(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D, name) {

    if (side_a != side_c || side_b != side_d || angle_A != 90 || angle_B != 90 || angle_C != 90 || angle_D != 90) {
        throw Error("Ошибка создания фигуры. Причина: стороны не равны или углы не равны 90");
    }
}