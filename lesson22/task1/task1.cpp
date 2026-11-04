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
};

int main() {
    setlocale(LC_ALL, "RU");
    try {
        smart_ar arr(5);
        arr.add_el(1);
        arr.add_el(4);
        arr.add_el(155);
        arr.add_el(14);
        arr.add_el(15);

        cout << arr.get_el(1) << endl; 
    }
    catch (const exception& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}