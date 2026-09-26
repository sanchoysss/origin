#include <iostream>
using namespace std;

void print_dynamic_array(int* arr, int logical_size, int fact_size) {
    for (int i = 0; i < fact_size; i++) {
        if (i < logical_size) {
            cout << arr[i];
        }
        else {
            cout << "_";
        }

        if (i < fact_size - 1) {
            cout << " ";
        }
    }
    
}


int main()
{
    setlocale(LC_ALL, "RU");

    int fact_size = 0;
    int logical_size = 0;

    cout << "Введите фактичеcкий размер массива: ";
    cin >> fact_size;

    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if (logical_size > fact_size) {
        std::cout << "Логический размер не может превышать фактический" << std::endl;
        return 1;
    }

    int* arr = new int[fact_size];

    for (int i = 0; i < logical_size; i++) {
        cout << "Введите arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, fact_size);

    delete[] arr;
    return 0;
}
