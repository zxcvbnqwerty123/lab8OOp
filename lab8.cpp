#pragma once
#include "Property.h"
#include"Owner.h"
#include"Car.h"
#include "CountryHouse.h"
#include"Apartment.h"
int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Owner*> owners;
    Owner* owner1 = new Owner("Иванов Иван Иванович", "123456789012");
    owner1->addProperty(new Apartment(5000000, 120.0));
    owner1->addProperty(new Car(1500000, 150.0));
    owner1->addProperty(new CountryHouse(3000000, 40));
    owner1->addProperty(new Car(800000, 80.0));
    owners.push_back(owner1);
    for (auto o : owners) {
        o->printInfo();
    }
    for (auto o : owners) delete o;
    return 0;
}