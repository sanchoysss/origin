#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
void Unique(std::vector<T>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        auto found = std::find(std::next(it), vec.end(), *it);
        if (found != vec.end()) {
            auto new_end = std::remove(found, vec.end(), *it);
            vec.erase(new_end, vec.end());
        }
    }
}
int main()
{
    std::vector<int> numbers = { 1, 1, 2, 5, 6, 1, 2, 4 };

    std::cout << "[IN]: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    Unique(numbers);

    std::cout << "[OUT]: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << "\n";

}

