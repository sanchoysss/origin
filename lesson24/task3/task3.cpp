#include <iostream>
#include <vector>
#include <algorithm>

class Counter {
private:
    int sum = 0;
    int count = 0;
public:
    Counter() : sum(0), count(0) {}

    void operator() (int number) {
        if (number % 3 == 0) {
            sum += number;
            count++;
        }
    }

    int get_sum() const {
        return sum;
    }
    int get_count() const {
        return count;
    }
};

int main()
{
    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };

    std::cout << "[IN]: ";
    for (int i : numbers) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    Counter res = std::for_each(numbers.begin(), numbers.end(), Counter());

    std::cout << "[OUT]: get_sum() = " << res.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << res.get_count() << std::endl;
}
