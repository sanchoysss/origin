#include <iostream>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;


int real_string_hash(const string& s, int p, int n) {
    uint64_t num_sum = 0;
    uint64_t pow_p = 1;

    for (size_t i = 0; i < s.length(); ++i) {
        uint64_t hash_val = static_cast<uint64_t>(s[i]);
        num_sum = (num_sum + hash_val * pow_p) % n;

        pow_p = (pow_p * p) % n;
    }


    return static_cast<int>(num_sum);
}



int main()
{
    setlocale(LC_ALL, "Russian");
    string input;
    int p, n;
    cout << "Введите p: ";
    cin >> p;
    cout << "Введите n: ";
    cin >> n;

    cin.ignore();

    do {
        cout << "Введите строку: ";
        getline(cin, input);
        

        int hash_value = real_string_hash(input, p, n);

        cout << "Хэш строки " << input << " = " << hash_value << endl;

    } while (input != "exit");


}
