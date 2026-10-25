#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void dfs(int vertex, int n, const vector<vector<int>>& matrix, vector<bool>& visited, vector<int>& order) {
    visited[vertex] = true;

    for (int neighbor = 0; neighbor < n; ++neighbor) {
        if (matrix[vertex][neighbor] == 1 && !visited[neighbor]) {
            dfs(neighbor, n, matrix, visited, order);
        }
    }
    order.push_back(vertex);
}

int main() {
    setlocale(LC_ALL, "RU");

    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла input.txt" << endl;
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

    vector<bool> visited(n, false);
    vector<int> order;

    for (int i = 0; i < n;++i) {
        if (!visited[i]) {
            dfs(i, n, matrix, visited, order);
        }
    }

    reverse(order.begin(), order.end());

    cout << "Топологический порядок вершин: ";
    for (int i = 0; i < order.size(); ++i) {
        cout << order[i] + 1 << " ";
    }
    cout << endl;

}