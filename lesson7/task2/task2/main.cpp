#include <iostream>
#include <string>

#include "Error.h"

#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrilateral.h"
#include "Parallelogram.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Square.h"


int main() {

	try {
		RightTriangle righttriangle(3, 4, 5, 45, 45, 90);
		std::cout << "Прямоугольный треугольник (стороны 3, 4, 5; углы 90, 45, 45) создан" << std::endl;
	}
	catch (const Error& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		RightTriangle badtriangle(3, 4, 5, 1, 1, 1);
		std::cout << "Прямоугольный треугольник (стороны 3, 4, 5; углы 1, 1, 1) создан" << std::endl;
		
	}
	catch (const Error& e) {
		std::cout  << e.what() << std::endl;
	}

return 0;
}