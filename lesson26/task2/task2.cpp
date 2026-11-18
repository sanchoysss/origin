#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <string>

template <typename Container>
void print_container(const Container& cont) {
    bool is_first = true;

    for (const auto& i: cont) {
        if (!is_first) {
            std::cout << ", ";
        }
        std::cout << i;
        is_first = false;
    }
    std::cout << '\n';
}
int main() {
    setlocale(LC_ALL, "RU");

    std::set<std::string> test_set = { "one", "two", "three", "four" };
    std::cout << "Для set: ";
    print_container(test_set); 

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    std::cout << "Для list: ";
    print_container(test_list); 

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    std::cout << "Для vector: ";
    print_container(test_vector); 

    return 0;
}