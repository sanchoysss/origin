#include <iostream>
#include <vector>
using namespace std;


void print_sorce(const vector<int>& arr) {
    cout << "Исходный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int get_level(int index) {
    int level = 0;
    while (index > 0) {
        index = (index - 1) / 2;
        level++;
    }
    return level;
}


void print_pyramid(const vector<int>& arr) {
    int size = arr.size();
    if (size == 0) {
        cout << "Пирамида пуста" << endl;
        return;
    }

    cout << "Пирамида: " << endl;

    for (int i = 0; i < size; i++) {
        int level = get_level(i);

        if (i == 0) {
            cout << level << " root " << arr[i] << endl;
        }
        else {
            int parent_id = (i - 1) / 2;
            int parent_val = arr[parent_id];

            if (i % 2 != 0) {
                cout << level << " left(" << parent_val << ") " << arr[i] << endl;
            }
            else {
                cout << level << " right(" << parent_val << ") " << arr[i] << endl;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> test1 = { 1, 3, 6, 5, 9, 8 };
    print_sorce(test1);
    print_pyramid(test1);
    cout << endl;

    vector<int> test2 = { 94, 67, 18, 44, 55, 12, 6, 42 };
    print_sorce(test2);
    print_pyramid(test2);
    cout << endl;

    vector<int> test3 = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    print_sorce(test3);
    print_pyramid(test3);
    cout << endl;
}
