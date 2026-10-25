#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла" << endl;
        return 1;
    }

    int n;
    inputFile >> n; 

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> matrix[i][j];
        }
    }
    inputFile.close(); 

    cout << "Текстовый вид орграфа:" << endl;

    for (int i = 0; i < n;++i) {
        cout << i + 1 << ": ";
        bool find = false;

        for (int j = 0; j < n;++j) {
            if (matrix[i][j] == 1) {
                find = true;
                cout << j + 1 << ' ';
            }
        }
        if (!find) {
            cout << "нет";
        }
        cout << endl;
    }
    return 0;
}
