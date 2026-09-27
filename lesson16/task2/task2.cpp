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
    cout << endl;
}


int* append_to_dynamic_array(int* arr, int& logical_size, int& fact_size, int new_el) {
    if (logical_size < fact_size) {
        arr[logical_size] = new_el;
        logical_size++;
        return arr;
    }

    fact_size *= 2;
    int* new_arr = new int[fact_size];

    for (int i = 0; i < logical_size; i++) {
        new_arr[i] = arr[i];
    }

    new_arr[logical_size] = new_el;
    logical_size++;

    delete[] arr;
    return new_arr;
}

int main()
{
    setlocale(LC_ALL, "RU");

    int fact_size = 0;
    int logical_size = 0;

    cout << "Введите фактичеcкий размер массива: ";
    cin >> fact_size;

    cout << "Введите логический размер массива: ";
    cin >> logical_size;

    if (logical_size > fact_size) {
        cout << "Логический размер не может превышать фактический" << endl;
        return 1;
    }

    int* arr = new int[fact_size];

    for (int i = 0; i < logical_size; i++) {
        cout << "Введите arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, fact_size);

    int new_el = 0;

    while (true) {
        cout << "Введите элемент для добавления: ";
        cin >> new_el;

        if (new_el == 0) {
            break;
        }

        arr = append_to_dynamic_array(arr, logical_size, fact_size, new_el);

        cout << "Динамический массив: ";
        print_dynamic_array(arr, logical_size, fact_size);
    }


    cout << "Спасибо! Ваш массив: ";
    print_dynamic_array(arr, logical_size, fact_size);

    delete[] arr;
    return 0;
}
