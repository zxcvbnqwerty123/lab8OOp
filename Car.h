#pragma once
#include "Property.h"
#include"taxrates.h"
class Car : public Property {
    double horsepower;
public:
    Car(unsigned int w, double hp) : Property(w), horsepower(hp) {}
    double calculateTax() override {
        if (horsepower < TAX_RATES::LOW_HORSEPOWER)
            return worth * TAX_RATES::CAR_TAX;
        else if (horsepower > TAX_RATES::HIGH_HORSEPOWER)
            return worth * TAX_RATES::CAR_LUXURY_TAX;
        return worth * TAX_RATES::CAR_TRUCK_TAX;
    }
};
