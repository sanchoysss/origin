#include <iostream>
#include <string>

using namespace std;

int simple_string_hash(const string& s) {
    int hash = 0;
    for (char c : s) {
        hash += static_cast<int>(c);
    }
    return hash;
}

int find_substring_light_rabin_karp(string source, string substring){
    size_t len_source = source.length();
    size_t len_sub = substring.length();

    if (len_source < len_sub) return -1;

    int sub_hash = simple_string_hash(substring);
    int src_hash = simple_string_hash(source.substr(0, len_sub));

    for (size_t i = 0; i <= len_source - len_sub; ++i) {
        
        if (src_hash == sub_hash) {
            bool match = true;

            for (size_t j = 0; j < len_sub; ++j) {
                if (source[i + j] != substring[j]) {
                    match = false;
                    break;
                }
            }

            if (match) return static_cast<int>(i);
        }
        if (i < len_source - len_sub){
            src_hash = src_hash - static_cast<int>(source[i]) + static_cast<int>(source[i + len_sub]);
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");

    string source;
    cout << "Введите строку, в которой будет осуществляться поиск: ";
    getline(cin, source);

    string substring;
    while (true) { 
        cout << "Введите подстроку, которую нужно найти: ";
        getline(cin, substring);

        if (substring == "exit") { 
            break;
        }

        int index = find_substring_light_rabin_karp(source, substring);

        if (index != -1) {
            cout << "Подстрока " << substring << " найдена по индексу " << index << endl;
        }
        else {
            cout << "Подстрока " << substring << " не найдена" << endl;
        }
    }
    return 0;
}
