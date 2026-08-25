#include <iostream>
#include "TaskLibraryDynamic.h"
#include <Windows.h>
int main() {

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;

	TaskLibraryDynamic::Leaver dynamictask{};
	std::cout << dynamictask.leave(name) << std::endl;

	return 0;
}