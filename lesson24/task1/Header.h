#pragma once
#include <vector>

template <class T>
T sqr(T val) {
	return val * val;
}

template <class T>
std::vector<T> sqr(const std::vector<T>& vec) {
	std::vector<T> result;
	result.reserve(vec.size());

	for (const auto& i : vec) {
		result.push_back(sqr(i));
	}

	return result;
}