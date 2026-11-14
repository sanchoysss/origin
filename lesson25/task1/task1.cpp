#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

int main()
{
    std::string text;
    std::cout << "IN: ";
    std::getline(std::cin, text);

    std::unordered_map<char, int> frequ;
    for (char ch : text) {
        frequ[ch]++;
    }

    std::vector<std::pair<char, int>> sorted_chars(frequ.begin(), frequ.end());

    std::sort(sorted_chars.begin(), sorted_chars.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

    std::cout << "OUT: " << std::endl;
    for (const auto& pair : sorted_chars) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }

};