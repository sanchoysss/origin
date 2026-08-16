#include <iostream>
#include <string>
#include <exception>


class bad_length : public std::exception {
public:
	const char* what() const noexcept override {
		return "Вы ввели слово запретной длины! До свидания";
	}
};

int function(std::string str, int forbidden_length) {
	int current_length = static_cast<int>(str.length());

	if (current_length == forbidden_length) {
		throw bad_length();
	}
	return current_length;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int forbidden_length = 0;
	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;
	std::cin.ignore();

	while (true) {
		std::string user_word;
		std::cout << "Введите слово: ";
		std::getline(std::cin, user_word);
		

		try {
			int length = function(user_word, forbidden_length);
			std::cout << "Длина слова \"" << user_word << "\" равна " << length << std::endl;
		}

		catch (const bad_length& e) {
			std::cout << e.what() << std::endl;
			break;
		}
	}
	return 0;
}