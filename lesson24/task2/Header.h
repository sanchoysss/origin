#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <utility>

template <class T>
class table {
private:
	std::vector<std::vector <T>> data;
	size_t rows;
	size_t cols;
public:
	table(size_t num_rows, size_t num_cols)
		:rows(num_rows), cols(num_cols), data(num_rows, std::vector<T>(num_cols)) {
	}

	std::vector<T>& operator[](size_t index) {
		return data[index];
	}

	 const std::vector<T>& operator[](size_t index) const {
		return data[index];
	}

	 std::pair<size_t, size_t> Size() const {
		 return { rows, cols };
	 }
};

#endif
