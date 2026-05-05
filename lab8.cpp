#include <iostream>
#include <vector>
#include <string>
#include "Owner.h"
#include "Apartment.h"
#include "Car.h"
#include "CountryHouse.h"

void showOwnersMenu(const std::vector<Owner*>& owners) {
    std::cout << "\nСПИСОК ВЛАДЕЛЬЦЕВ" << std::endl;
    for (size_t i = 0; i < owners.size(); i++) {
        std::cout << i + 1 << ". Выбрать владельца #" << i + 1 << std::endl;
    }
    std::cout << "8.Добавить нового собственника" << std::endl;
    std::cout << "9.Удалить собственника" << std::endl;
    std::cout << "0. Выход из программы" << std::endl;
    std::cout << "Выберите номер владельца: ";
}
void showPropertyMenu() {
    std::cout << "\n--- ДЕЙСТВИЯ С ИМУЩЕСТВОМ ---" << std::endl;
    std::cout << "1. Показать всю информацию и налоги" << std::endl;
    std::cout << "2. Добавить квартиру" << std::endl;
    std::cout << "3. Добавить машину" << std::endl;
    std::cout << "4. Удалить объект по индексу" << std::endl;
    std::cout << "0. Вернуться к списку владельцев" << std::endl;
    std::cout << "Выберите действие: ";
}
int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Owner*> owners;
    owners.push_back(new Owner("Иванов И.И.", "123456789012"));
    owners.push_back(new Owner("Безос Джефф", "676767676767"));
    owners.push_back(new Owner("Правин Александр", "1488696969"));
    //Иванов
    owners[0]->addProperty(new Apartment(5000000, 65.5));
    owners[0]->addProperty(new Car(1200000, 150.0));
    owners[0]->addProperty(new CountryHouse(8000000, 25));
    owners[0]->addProperty(new Car(300000, 75.0));
    //Безос
    owners[1]->addProperty(new Apartment(150000000, 500.0));
    owners[1]->addProperty(new CountryHouse(300000000, 15));
    owners[1]->addProperty(new Car(50000000, 1000.0));
    owners[1]->addProperty(new Apartment(80000000, 250.0));
    //Правин
    owners[2]->addProperty(new Car(500000, 105.0));
    owners[2]->addProperty(new Car(600000, 110.0));
    owners[2]->addProperty(new Apartment(3500000, 42.0));
    owners[2]->addProperty(new CountryHouse(2000000, 100));
    int ownerChoice = -1;
    while (true) {
        showOwnersMenu(owners);
        if (!(std::cin >> ownerChoice)) break;
        if (ownerChoice == 0) break;
        if (ownerChoice < 1 || ownerChoice > owners.size()) {
            std::cout << "Неверный выбор!" << std::endl;
            continue;
        }
        if (ownerChoice == 8) {
            std::string name, inn;
            std::cout << "Введите ФИО: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Введите ИНН: ";
            std::cin >> inn;
            owners.push_back(new Owner(name, inn));
            std::cout << "Собственник добавлен!" << std::endl;
            continue;
        }
        if (ownerChoice == 9) {
            if (owners.empty()) {
                std::cout << "Удалять некого!" << std::endl;
                continue;
            }
            int idx;
            std::cout << "Введите номер владельца для удаления (1-" << owners.size() << "): ";
            std::cin >> idx;
            if (idx >= 1 && idx <= owners.size()) {
                delete owners[idx - 1];
                owners.erase(owners.begin() + (idx - 1));
                std::cout << "Собственник удален." << std::endl;
            }
            else {
                std::cout << "Неверный номер!" << std::endl;
            }
            continue;
        }
        Owner* currentOwner = owners[ownerChoice - 1];
        int propChoice = -1;
        while (propChoice != 0) {
            showPropertyMenu();
            std::cin >> propChoice;
            if (propChoice == 1) {
                currentOwner->printInfo();
            }
            else if (propChoice == 2) {
                unsigned int worth; double square;
                std::cout << "Стоимость и площадь квартиры: ";
                std::cin >> worth >> square;
                currentOwner->addProperty(new Apartment(worth, square));
            }
            else if (propChoice == 3) {
                unsigned int worth; double hp;
                std::cout << "Стоимость и л.с. машины: ";
                std::cin >> worth >> hp;
                currentOwner->addProperty(new Car(worth, hp));
            }
            else if (propChoice == 4) {
                int idx;
                std::cout << "Индекс для удаления (начиная с 0): ";
                std::cin >> idx;
                currentOwner->removeProperty(idx);
            }
        }
    }
    for (auto o : owners) delete o;

    return 0;
}