#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void dfs(int vertex, int n, const vector<vector<int>>& matrix, vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex + 1 << ' ';
    for (int neighbor = 0; neighbor < n; ++neighbor) {
        if (matrix[vertex][neighbor] == 1 && !visited[neighbor]) {
            dfs(neighbor, n, matrix, visited);
        }
    }
}


int main()
{
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
        for (int j = 0; j < n;++j) {
            inputFile >> matrix[i][j];
        }
    }
    inputFile.close();

    vector<bool> visited(n, false);
    cout << "Порядок обхода вершин: ";

    dfs(0, n, matrix, visited);
    
    return 0;
}

