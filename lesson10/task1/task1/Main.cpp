#include <iostream>
#include <string>

#include "TaskLibraryStatic.h"

int main()
{
	setlocale(LC_ALL, "RU");

	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;

	TaskLibraryStatic::Greeter statictask{};
	std::cout << statictask.greet(name) << std::endl;

	return 0;

}