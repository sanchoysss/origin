#include <iostream>
using namespace std;

int func(const int* arr, int size, int x) {
    int left = 0;
    int right = size - 1;

    int first_index = size;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] > x) {
            first_index = middle;
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return size - first_index;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
    int size = sizeof(arr) / sizeof(arr[0]);

    int x;
    cout << "Введите точку отсчета: ";
    cin >> x;
    int result = func(arr, size, x);

    cout << "Количество элементов в массиве, больших, чем " << x << ": " << result << endl;
    return 0;
}
