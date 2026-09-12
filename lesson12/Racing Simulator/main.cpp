
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;


#include "Boots.h"      
#include "Broom.h"      
#include "Camel.h"        
#include "Centaur.h"      
#include "Eagle.h"
#include "FastCamel.h"
#include "MagicCarpet.h"
#include "Race.h"




Transport* choosingTransport(int choice) {
	switch (choice) {
    case 1: return new Boots();      
    case 2: return new Broom();       
    case 3: return new Camel();       
    case 4: return new Centaur();
    case 5: return new Eagle();
    case 6: return new FastCamel();
    case 7: return new MagicCarpet();
    default: return nullptr;
    }
}



int main()
{
    
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

	
    while (true) {
    
        std::cout << "Добро пожаловать в гоночный симулятор!\n";
        std::cout << "1. Гонка для наземного транспорта\n";
        std::cout << "2. Гонка для воздушного транспорта\n";
        std::cout << "3. Гонка для наземного и воздушного транспорта\n";
        std::cout << "Выберите тип гонки: ";

        int raceTypeChoice;
        cin >> raceTypeChoice;

        double distance = 0;
        cout << "Укажите длину дистанции (должна быть положительна): ";
        cin >> distance;

        Race race(distance, static_cast<RaceType>(raceTypeChoice));

        std::vector<Transport*> addedTransports;
        bool raceStart = false;

        

        while (!raceStart) {
            int action = 0;
            cout << "1.Зарегистрировать транспорт" << endl;

            if (addedTransports.size() >= 2) {
                cout << "2. Начать гонку" << endl;
            }

            cout << "Выберите действие: ";
            cin >> action;
    
            if (action == 2 && addedTransports.size() >= 2) {
                raceStart = true;
                break;
            }

            cout << endl;

            if (action == 1) {
                while (true) {
                    cout << "Гонка для ";
                    if (race.getRaceType() == RaceType::Ground) { cout << "наземного транспорта"; }
                    else if (race.getRaceType() == RaceType::Air) { cout << "воздушного транспорта"; }
                    else { cout << "наземного и воздушного транспорта"; }

                    cout << ". Расстояние: " << race.getDistance() << endl;

                    if (!addedTransports.empty()) {
                        cout << "Зарегистрированные транспортные средства: ";

                        cout << addedTransports[0]->getName();

                        for (size_t i = 1; i < addedTransports.size(); i++) {
                            cout << " , " << addedTransports[i]->getName();
                        }

                    cout << endl;
                    }
                    cout << "1. Ботинки-вездеходы\n2. Метла\n3. Верблюд\n4. Кентавр\n5. Орёл\n6. Верблюд-быстроход\n7. Ковёр-самолёт\n0. Закончить регистрацию\n";
                    cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
                    
                    int choice;
                    cin >> choice;
                    cout << endl;
                    if (choice == 0) {
                        if (addedTransports.size() < 2) {
                            cout << "Должно быть зарегистрированно хотя бы 2 транспорта" << endl;
                        }
                        break;
                    }

                    Transport* t = choosingTransport(choice);
                    bool alreadyReg = false;


                    for (auto registered : addedTransports) {
                        if (registered->getName() == t->getName()) {
                            alreadyReg = true;
                            break;
                        }
                    }

                    if (alreadyReg) {
                        cout << t->getName() << " уже зарегистрирован!\n";
                        delete t; 
                    }

                    else if (!race.addTransport(t)) {
                        cout << "Неправильный тип транспортного средства" << endl;
                        delete t;
                    }

                    else {
                        addedTransports.push_back(t);
                        cout << t->getName() << " успешно зарегистрирован!" << endl;
                    }



            }
        }

        
    }
    cout << "\nРезультаты гонки:\n";
    auto results = race.run();

    for (size_t i = 0; i < results.size(); ++i){
        cout << i + 1 << ". " << results[i].name << ". Время: " << results[i].time << endl;
    }

    
    for (auto t : addedTransports) {
        delete t;
    }


    cout << "\n1. Провести ещё одну гонку" << endl;
    cout << "2. Выйти" << endl;
    cout << "Выберите действие: ";
    int nextStep;
    std::cin >> nextStep;

    if (nextStep == 2) {
        break; 
    }

    cout << endl;
    }

	return 0;
}
