#include <iostream>

void merge(int* arr, int left, int mid, int right) {
    int it1 = 0;
    int it2 = 0;
    int res_size = right - left;

    int* result = new int[res_size];

    while (left + it1 < mid && mid + it2 < right) {
        if (arr[left + it1] < arr[mid + it2]) {
            result[it1 + it2] = arr[left + it1];
            it1++;
        }
        else {
            result[it1 + it2] = arr[mid + it2];
            it2++;
        }
    }

    while (left + it1 < mid) {
        result[it1 + it2] = arr[left + it1];
        it1++;
    }
    while (mid + it2 < right) {
        result[it1 + it2] = arr[mid + it2];
        it2++;
    }

    for (int i = 0; i < res_size; i++) {
        arr[left + i] = result[i];
    }

    delete[] result;
}

void merge_sort_recursive(int* arr, int left, int right) {
    if (left + 1 >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    merge_sort_recursive(arr, left, mid);
    merge_sort_recursive(arr, mid, right);

    merge(arr, left, mid, right);
}

void merge_sort(int* arr, int size) {
    merge_sort_recursive(arr, 0, size);
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        
    }std::cout << "\n";
}

void test_array(int* arr, int size) {
    std::cout << "Исходный массив: ";
    print_array(arr, size);
    merge_sort(arr, size);

    std::cout << "Отсортированный массив: ";
    print_array(arr, size);
    std::cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "RU");
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    test_array(arr1, size1);

    // Тест 2
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    test_array(arr2, size2);

    // Тест 3
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    test_array(arr3, size3);
}
