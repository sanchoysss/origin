#include <iostream>
#include "Header.h"

int main()
{
	setlocale(LC_ALL, "RU");
	auto test = table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0] << std::endl;

	auto size = test.Size();
	std::cout << "Строк: " << size.first << std::endl;
	std::cout << "Столбцов: " << size.second << std::endl;


}
