#pragma once
#include "Property.h"
#include "taxrates.h"
class Apartment : public Property {
    double square;
public:
    Apartment(unsigned int w, double s) : Property(w), square(s) {}
    double calculateTax() override {
        if (square <= TAX_RATES::LIMIT_Apartment_SQUARE)
            return worth * TAX_RATES::Apartment_TAX;
        return worth * TAX_RATES::Apartment_LUXURY_TAX;
    }
};

