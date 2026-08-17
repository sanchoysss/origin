#include "EquilateralTriangle.h"
#include "Error.h"

EquilateralTriangle::EquilateralTriangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C) :
	Triangle(side_a, side_b, side_c, angle_A, angle_B, angle_C, "Равносторонний треугольник") {

	if (side_a != side_b || side_b != side_c || angle_A != 60 || angle_B != 60 || angle_C != 60) {
		throw Error("Ошибка создания фигуры. Причина: стороны не равны или углы не равны 60");
	}
}