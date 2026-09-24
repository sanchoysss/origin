#include <iostream>
using namespace std;

void count_sort(int* arr, int size) {
    const int minni = 10;
    const int maxi = 24;
    const int new_size = maxi - minni + 1;

    int count[new_size] = { 0 };

    for (int i = 0; i < size; i++) {
        count[arr[i]- minni]++;
    }

    int index = 0;
    for (int i = 0; i < new_size; ++i) {
        while (count[i] > 0) {
            arr[index] = i + minni;
            index++;
            count[i]--;

        }
    }
}

void print_arr(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";

    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int arr1[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Исходный массив: ";
    print_arr(arr1, size1);

    count_sort(arr1, size1);

    std::cout << "Отсортированный массив: ";
    print_arr(arr1, size1);

    return 0;
}

