#include <iostream>
#include <string>
class Counter {
private:
    int num;
public:
    void add() {
        num++;
    }

    void subtract() {
        num--;
    }

    int get_current() {
        return num;
    }

    Counter(int user_num) {
        this->num = user_num;
    }

    Counter() {
        num = 1;
    }
};

int main()
{
    std::setlocale(LC_ALL, "Russian");
    std::string choice;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> choice;
    
    int user_num;

    Counter counter;
    if (choice == "да") {
        
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> user_num;

        counter = Counter(user_num);
    }
    else {
        counter = Counter();
    }

    char command;
    bool com_running = true;
    while (com_running) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        switch (command) {
            case '+':
                counter.add();
                break;
            case '-':
                counter.subtract();
                break;
            case '=':
                std::cout << counter.get_current() << std::endl;
                break;
            case 'x':
                std::cout << "До свидания!" << std::endl;
                com_running = false;
                break;
        }
    }

}
