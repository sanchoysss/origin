#include <iostream>
#include <cassert>
#include <stdexcept>
#include <typeinfo>
#include "extended_array.h"

void test1() {
    ExtArray<int> empty_arr{};
    assert(empty_arr.mean() == 0);
    assert(empty_arr.median() == 0);
    assert(empty_arr.mode().second == 0);
    std::cout << "Test 1 OK" << std::endl;
}
void test2() {
    ExtArray<int> arr{ 1, 2, 3, 4, 5 };
    assert(arr.mean(1, 4) == 3.0);

    bool exception_caught = false;
    try {
        arr.mean(4, 2);
    }
    catch (const std::invalid_argument&) {
        exception_caught = true;
    }
    assert(exception_caught);
    std::cout << "Test 2 OK" << std::endl;
}
void test3() {
    ExtArray<int> valid_int_bits{ 1, 0, 1, 1, 0 };
    assert(valid_int_bits.checkSum() == 3);

    ExtArray<bool> valid_bool_bits{ true, false, true };
    assert(valid_bool_bits.checkSum() == 2);

    bool bad_type_caught = false;
    try {
        ExtArray<double> double_arr{ 1.0, 0.0 };
        double_arr.checkSum();
    }
    catch (const std::bad_typeid&) {
        bad_type_caught = true;
    }
    assert(bad_type_caught);


    bool logic_error_caught = false;
    try {
        ExtArray<int> invalid_int_bits{ 0, 1, 5, 0 };
        invalid_int_bits.checkSum();
    }
    catch (const std::logic_error&) {
        logic_error_caught = true;
    }
    assert(logic_error_caught);

    std::cout << "Test 3 OK" << std::endl;
}

int main()
{
    try {
        test1();
        test2();
        test3();

    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
