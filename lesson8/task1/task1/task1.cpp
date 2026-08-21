#include <iostream>
using namespace std;
#include <string>
#include <cassert>
#include <stdexcept>
#include <numeric> 
class Fraction {
	int numerator;
	int denominator;

	void reduce() {
		if (denominator == 0) {
			throw std::invalid_argument("На ноль делить нельзя (тест 8)");
		}
		if (denominator < 0) {//меняем знаки
			numerator = -numerator;
			denominator = -denominator;
		}

		int gcd_val = std::gcd(std::abs(numerator), std::abs(denominator));//нахождение НОД по модулю, чтобы знаки не перевернулись
		numerator /= gcd_val; //делим на НОД, т.е. сокращаем дробь
		denominator /= gcd_val;
	}

public:
	Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
		reduce();
	}


	bool operator==(const Fraction& right) const {
		//умножаем дроби крест накрест и сравниваем результат
		return numerator * right.denominator == denominator * right.numerator;
	}
	bool operator!=(const Fraction& right) const {
		//сравниваем дроби через готовое == и используем !
		return !(*this == right);
	}

	bool operator<(const Fraction& right) const {
		//умножаем дроби крест накрест и сравниваем результат
		return numerator * right.denominator < denominator * right.numerator;
	}
	bool operator>(const Fraction& right) const {
		//переворачиваем сравнение и используем готовое <
		return right < *this;
	}

	bool operator<=(const Fraction& right) const {
		//если число меньше или равно то оно точно не больше
		return !(*this > right);
	}
	bool operator>=(const Fraction& right) const {
		//если число больше или равно то оно точно не меньше
		return !(*this < right);
	}

	

	Fraction operator+(const Fraction& right) const {
		int new_num = numerator * right.denominator + right.numerator * denominator;
		int new_den = denominator * right.denominator;

		return Fraction(new_num, new_den);
	}

	Fraction operator-(const Fraction& right) const {
		int new_num = numerator * right.denominator - right.numerator * denominator;
		int new_den = denominator * right.denominator;

		return Fraction(new_num, new_den);
	}

	Fraction operator*(const Fraction& right) const {
		return Fraction(numerator * right.numerator, denominator * right.denominator);
	}

	Fraction operator/(const Fraction& right) const {
		return Fraction(numerator * right.denominator, denominator * right.numerator);
	}

	//УНАРНЫЙ МИНУС
	Fraction operator-() const {
		return Fraction(-numerator, denominator);
	}


	Fraction& operator++() {//префиксный инкремент
		numerator += denominator;
		return *this;
	}
	Fraction operator++(int) {//постфиксный инкремент
		Fraction temp = *this;
		numerator += denominator;
		return temp;
	}


	Fraction& operator--() {//префиксный декремент
		numerator -= denominator;
		return *this;
	}
	Fraction operator--(int) {//постфиксный декремент
		Fraction temp = *this;
		numerator -= denominator;
		return temp;
	}


	std::string dump() const {
		return std::to_string(numerator) + "/" + std::to_string(denominator);
	}

};

int main() {
	setlocale(LC_ALL, "RU");

	// Тест 1: Проверка конструкторов и dump
	{
		Fraction f1(3, 4);
		Fraction f2(4, 5);
		assert(f1.dump() == "3/4");
		assert(f2.dump() == "4/5");
	}
	// Тест 2: Проверка неравенства    
	{
		Fraction f1(4, 3);
		Fraction f2(6, 11);
		assert(!(f1 == f2));
		assert(f1 != f2);
		assert(!(f1 < f2));
		assert(f1 > f2);
		assert(!(f1 <= f2));
		assert(f1 >= f2);
	}
	// Тест 3: Проверка равенства    
	{
		Fraction f1(4, 3);
		Fraction f2(8, 6);
		assert(f1 == f2);
		assert(!(f1 != f2));
		assert(!(f1 < f2));
		assert(!(f1 > f2));
		assert(f1 <= f2);
		assert(f1 >= f2);
	}

	// Тест 4: Проверка сценария    
	{
		Fraction f1(3, 4);
		Fraction f2(4, 5);
		assert((f1 + f2).dump() == "31/20"); // 3/4 + 4/5 = 31/20        
		assert((f1 - f2).dump() == "-1/20"); // 3/4 - 4/5 = -1/20        
		assert((f1 * f2).dump() == "3/5");   // 3/4 * 4/5 = 3/5        
		assert((f1 / f2).dump() == "15/16"); // 3/4 / 4/5 = 15/16        
		assert((++f1 * f2).dump() == "7/5"); // ++3/4 * 4/5 = 7/5        
		assert(f1.dump() == "7/4");          // Значение дроби 1 = 7/4        
		assert((f1-- * f2).dump() == "7/5"); // 7/4-- * 4/5 = 7/5        
		assert(f1.dump() == "3/4");          // Значение дроби 1 = 3/4    
	}

	// Тест 5: Дополнительные проверки с унарным минусом    
	{
		Fraction f1(2, 3);
		Fraction f2(-2, 3);
		assert((-f1).dump() == "-2/3");
		assert((-f2).dump() == "2/3");
		assert((-f1) == f2);
	}

	// Тест 6: Проверка сокращения дробей    
	{
		Fraction f1(4, 8);
		Fraction f2(2, 4);
		Fraction f3(1, 2);
		assert(f1.dump() == "1/2");
		assert(f2.dump() == "1/2");
		assert(f3.dump() == "1/2");
		assert(f1 == f2);
		assert(f2 == f3);
	}

	// Тест 7: Проверка с отрицательными дробями    
	{
		Fraction f1(-3, 4);
		Fraction f2(3, -4);
		Fraction f3(-3, -4);
		assert(f1.dump() == "-3/4");
		assert(f2.dump() == "-3/4");
		assert(f3.dump() == "3/4");
		assert(f1 == f2);
		assert(f1 != f3);
	}


	// Тест 8 проверка на ноль
	try {
		Fraction(1, 0);
		cout << "ошибка не сработала" << endl;
	}
	catch (const std::invalid_argument& e) {
		cout << e.what() << endl;
	}
	

	std::cout << "All tests passed!" << std::endl;
	return 0;
}

