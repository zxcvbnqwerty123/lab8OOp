#pragma once
#include "Property.h"
#include"taxrates.h"
class CountryHouse : public Property {
    unsigned int distanceFromCity;
public:
    CountryHouse(unsigned int w, unsigned int dist) : Property(w), distanceFromCity(dist) {}
    double calculateTax() override {
        if (distanceFromCity <= TAX_RATES::LIMIT_DISTANCE_FROM_CITY)
            return worth * TAX_RATES::Apartment_TAX;
        return worth * TAX_RATES::COUNTRY_HOUSE_TAX;
    }
};

