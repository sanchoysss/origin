#include <iostream>
#include <vector>
#include "Header.h"

template <class T>
void print_vector(const std::vector<T>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i];
		if (i + 1 < vec.size()) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

int main() {
	int number = 5;
	std::cout << "[IN]: " << number << std::endl;
	std::cout << "[OUT]: " << sqr(number) << std::endl;

	std::vector<int> vec = { -1, 5, 55 };
	std::cout << "[IN]: ";
	print_vector(vec);

	std::vector<int> result_vec = sqr(vec);
	std::cout << "[OUT]: ";
	print_vector(result_vec);
}