#include <iostream>
#include <string>
#include <fstream>
#include <string_view>
class Adress {
private:
	std::string City;
	std::string Street;
	int House;
	int Appartment;

public:
	Adress() : House(0), Appartment(0) {}

	Adress(std::string_view City, std::string_view Street, int House,
		int Appartment) : City(City), Street(Street), House(House),
		Appartment(Appartment) {
	}

	std::string get_output_address() {
		return City + ", " + Street + ", " + std::to_string(House) + ","+std::to_string(Appartment);
	}
};
int main() {
	std::setlocale(LC_ALL, "RU");

	std::ifstream file("in.txt");
	if (!file.is_open()) {
		std::cout << "Error...Не удалось открыть файл";
		return 1;
	}

	int n;
	file >> n;

	Adress* adresses = new Adress[n];

	for (int i = 0; i < n; i++) {
		std::string City;
		std::string Street;
		int House;
		int Appartment;
		file >> City >> Street >> House >> Appartment;
		adresses[i] = Adress(City, Street, House, Appartment);
	}

	file.close();

	std::ofstream out_file("out.txt");

	if (!out_file.is_open()) {
		std::cout << "Ошибка открытия файла";
		delete[] adresses;
		return 1;
	}

	out_file << n << std::endl;
	for (int i = n - 1; i >= 0; i--) {
		out_file << adresses[i].get_output_address() << std::endl;
	}

	out_file.close();
	delete[] adresses;
	return 0;
}