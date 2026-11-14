#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
private:
    T* data;
    int curr_size;  
    int max_capacity;

public:
    MyVector() : data(nullptr), curr_size(0), max_capacity(0) {}

    ~MyVector() {
        delete[] data;
    }

    int size() const {
        return curr_size;
    }
    int capacity() const {
        return max_capacity;
    }

    T& at(int index) {
        if (index < 0 or index >= curr_size) {
            throw std::out_of_range("индекс за пределами вектора");
        }
        return data[index];
    }

    void push_back(T value) {
        if (curr_size == max_capacity) {
            int new_cap = (max_capacity == 0) ? 1 : max_capacity * 2;
            T* new_data = new T[new_cap];

            for (int i = 0; i < curr_size; ++i) { 
                new_data[i] = data[i]; 
            }

            delete[] data;
            data = new_data;
            max_capacity = new_cap;
        }

        data[curr_size] = value;
        curr_size++;
    }
};



int main()
{
    setlocale(LC_ALL, "");
    MyVector<int> vec;

    for (int i = 1; i <= 4; ++i) {
        vec.push_back(i);
        std::cout << "Добавили " << i
            << ", размер: " << vec.size()
            << ", вместимость: " << vec.capacity() << std::endl;
    }

    std::cout << "Элемент с индексом 3: " << vec.at(3) << std::endl;
}
