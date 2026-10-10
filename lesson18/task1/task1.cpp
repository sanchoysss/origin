#include <iostream>
#include <string>
using namespace std;


int simple_string_hash(const string s) {
    int hash = 0;

    for (char c : s) {
        hash += static_cast<int>(c);
    }
    return hash;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string input;
    do {
        cout << "Введите строку: ";
        getline(cin, input);

        int hash_value = simple_string_hash(input);

        cout << "Наивный хэш строки " << input << " = " << hash_value << std::endl;
    
    } while (input != "exit");


}
