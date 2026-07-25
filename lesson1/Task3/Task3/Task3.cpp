#include <iostream>
#include <string>

struct Adress {
	std::string City;
	std::string Street;
	int House;
	int Appartment;
	int Index;
};

void print(const Adress& adr) {
	std::cout << "Город: " << adr.City << std::endl;
	std::cout << "Улица: " << adr.Street << std::endl;
	std::cout << "Номер дома: " << adr.House << std::endl;
	std::cout << "Номер квартиры: " << adr.Appartment << std::endl;
	std::cout << "Индекс: " << adr.Index << std::endl;
	std::cout << "\n";
}

int main() {
	setlocale(LC_ALL, "Russian");

	Adress adr1;
	adr1.City = "Москва";
	adr1.Street = "Арбат";
	adr1.House = 12;
	adr1.Appartment = 8;
	adr1.Index = 123456;

	Adress adr2;
	adr2.City = "Ижевск";
	adr2.Street = "Пушкина";
	adr2.House = 59;
	adr2.Appartment = 143;
	adr2.Index = 953769;

	print(adr1);
	print(adr2);
	return 0;
}