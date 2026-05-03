#pragma once
#include<string>
#include<vector>
#include<iostream>
#include "Property.h"
using namespace std;
class Owner
{
	string fullname;
	string inn;
	vector<Property*> properties;
public:
    Owner(std::string name, std::string i) : fullname(name), inn(i) {}
    ~Owner() {
        for (auto p : properties) delete p;
    }
    void addProperty(Property* p) {
        properties.push_back(p);
    }
    void removeProperty(int index) {
        if (index >= 0 && index < properties.size()) {
            delete properties[index];
            properties.erase(properties.begin() + index);
        }
    }
    double getTotalTax() {
        double total = 0;
        for (auto p : properties) {
            total += p->calculateTax();
        }
        return total;
    }
    void printInfo() {
        std::cout << "Владелец: " << fullname << " (ИНН: " << inn << ")" << std::endl;
        std::cout << "Общий налог на имущество: " << getTotalTax() << " руб." << std::endl;
    }
};

