#include <iostream>
#include <string>
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


int* remove_dynamic_array_head(int* arr, int& logical_size, int& fact_size) {
    if ((logical_size - 1) > (fact_size / 3)) {
        for (int i = 1; i < logical_size; i++) {
            arr[i - 1] = arr[i];   
        }
        logical_size--;
        return arr;
    }

    fact_size /= 3;

    if (fact_size < 1) {
        fact_size = 1;
    }
    int* new_arr = new int[fact_size];
    for (int i = 1; i < logical_size; i++) {
        new_arr[i - 1] = arr[i];
    }
    logical_size--;
    delete[] arr;
    return new_arr;

}

int main()
{
    setlocale(LC_ALL, "");

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

    char answer;

    while (true) {
        cout << "Удалить первый элемент? (y/n): ";
        cin >> answer;

        if (answer == 'y') {

            if (logical_size == 0) {
                cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!";
                delete[] arr;
                return 0;
            }

            arr = remove_dynamic_array_head(arr, logical_size, fact_size);

            cout << "Динамический массив: ";
            print_dynamic_array(arr, logical_size, fact_size);
        }
        else if (answer == 'n') {
            cout << "Спасибо! Ваш динамический массив: ";
            print_dynamic_array(arr, logical_size, fact_size);
            break;
        }
    }


    delete[] arr;
    return 0;
}