#include <iostream>
#include <stdexcept>
using namespace std;

class smart_ar {
private:
    int* data;
    size_t emkost;
    size_t size;

    void resize(size_t new_emkost) {
        int* new_data = new int[new_emkost];

        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;

        data = new_data;
        emkost = new_emkost;
    }

public:
    explicit smart_ar(size_t start_emk) {
        emkost = start_emk;
        size = 0;

        if (emkost == 0) { data = nullptr; }
        else { data = new int[emkost]; }
    }

    ~smart_ar() {
        delete[] data;
    }

    void add_el(int val) {
        if (size >= emkost) {
            size_t new_emkost = (emkost == 0) ? 1 : emkost * 2;
            resize(new_emkost);
        }
        data[size] = val;
        size++;
    }

    int get_el(size_t indx) const {
        if (indx >= size) {
            throw out_of_range("Индекс за пределами массива");
        }
        return data[indx];
    }



    smart_ar(const smart_ar& other) {
        emkost = other.emkost;
        size = other.size;

        if (emkost == 0) {
            data = nullptr;
        }
        else {
            data = new int[emkost];

            for (size_t i = 0; i < size;++i) {
                data[i] = other.data[i];
            }
        }
    }

    smart_ar& operator=(const smart_ar& other) {
        if (this == &other) {
            return *this;
        }

        int* new_data = nullptr;
        if (other.emkost > 0) {
            new_data = new int[other.emkost];

            for (size_t i = 0; i < other.size;++i) {
                new_data[i] = other.data[i];
            }
        }

        delete[] data;

        data = new_data;
        emkost = other.emkost;
        size = other.size;

        return *this;
    }

};

int main() {
    setlocale(LC_ALL, "RU");
    try {
        smart_ar arr(5);
        arr.add_el(1);
        arr.add_el(4);
        arr.add_el(155);
        
        smart_ar arr2 = arr;

        smart_ar arr3(0);
        arr3 = arr;

        cout << "Оригинал элемент 1: " << arr.get_el(1) << endl;
        cout << "Копия 1 элемент 1: " << arr2.get_el(1) << endl;
        cout << "Копия 2 элемент 1: " << arr3.get_el(1) << endl;
    }
    catch (const exception& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}