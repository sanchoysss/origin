#include <iostream>
#include <set>

int main()
{
    int count;
    std::cout << "[IN]:" << std::endl;
    std::cin >> count;

    std::set<int> unique_numbers;
    for (int i = 0; i < count; ++i) {
        int num;
        std::cin >> num;
        unique_numbers.insert(num);
    }

    std::cout << "[OUT]:" << std::endl;

    for (auto it = unique_numbers.rbegin(); it != unique_numbers.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}
