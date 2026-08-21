#include "my_first_cmake_project.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    cout << "Введите имя: ";
    string name;
    getline(cin, name);
    cout << "Здравствуйте, " << name << "!" << endl;

    return 0;
}
