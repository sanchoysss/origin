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
    explicit smart_ar(size_t initial_capacity)
        : emkost(initial_capacity), size(0) {
        if (emkost == 0) {
            data = nullptr;
        }
        else {
            data = new int[emkost];
        }
    }
    ~smart_ar() {
        delete[] data;
    }

    smart_ar(const smart_ar&) = delete;
    smart_ar& operator=(const smart_ar&) = delete;

    
    void add_element(int value) {
        if (size >= emkost) {
            size_t new_capacity = (emkost == 0) ? 1 : emkost * 2;
            resize(new_capacity); 
        }
        data[size] = value;
        size++;
    }

    
    int get_element(size_t index) const {
        if (index >= size) {
            throw out_of_range("Индекс за пределами массива!");
        }
        return data[index];
    }
};

int main() {
    try {
        smart_ar arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);

        cout << arr.get_element(1) << endl; 
    }
    catch (const exception& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}