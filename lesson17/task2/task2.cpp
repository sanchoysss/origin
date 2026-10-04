#include <iostream>
#include <vector>
#include <string>
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

void print_single_node(const vector<int>& arr, int i) {
    int level = get_level(i);
    if (i == 0) {
        cout << level << " root " << arr[i];
    }
    else {
        int parent_id = (i - 1) / 2;
        int parent_val = arr[parent_id];
        if (i % 2 != 0) {
            cout << level << " left(" << parent_val << ") " << arr[i];
        }
        else {
            cout << level << " right(" << parent_val << ") " << arr[i];
        }
    }
}

void print_pyramid(const vector<int>& arr) {
    int size = arr.size();
    if (size == 0) {
        cout << "Пирамида пуста" << endl;
        return;
    }
    cout << "Пирамида: " << endl;
    for (int i = 0; i < size; i++) {
        print_single_node(arr, i);
        cout << endl;
    }
}


bool go_up(int current_indx, int& next_index) {
    if (current_indx == 0) {
        return false;
    }
    next_index = (current_indx - 1) / 2;
    return true;
 }

bool go_left(int current_indx, int size, int& new_index) {
    int target = 2 * current_indx + 1;
    if (target >= size) {
        return false;
    }
    new_index = target;
    return true;
}

bool go_right(int current_indx, int size, int& new_index) {
    int target = 2 * current_indx + 2;
    if (target >= size) {
        return false;
    }
    new_index = target;
    return true;
}

int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> test1 = { 1, 3, 6, 5, 9, 8 };
    print_sorce(test1);
    print_pyramid(test1);

    int current_indx = 0;
    string command;

    do {
        cout << "Вы находитесь здесь: ";
        print_single_node(test1, current_indx);
        cout << endl;

        cout << "Введите команду: ";
        cin >> command;

        if (command == "exit") {
            break;
        }

        int next_indx = current_indx;

        if (command == "up") {
            if (go_up(current_indx, next_indx)) {
                current_indx = next_indx;
                cout << "Ок" << endl;
            }
            else {
                cout << "Ошибка! Отсутствует родитель" << endl;
            }
        }

        else if (command == "left") {
            if (go_left(current_indx, test1.size(), next_indx)) {
                current_indx = next_indx;
                cout << "Ок" << endl;
            }
            else {
                cout << "Ошибка! Отсутствует левый потомок" << endl;
            }

        }

        else if (command == "right") {
            if (go_right(current_indx, test1.size(), next_indx)) {
                current_indx = next_indx;
                cout << "Ок" << endl;
            }
            else {
                cout << "Ошибка! Отсутствует правый потомок" << endl;
            }
        }


        else {
            cout << "Ошибка! Неизвестная команда. Попробуйте up, left, right или exit." << endl;
        }


    } while (command != "exit");

}