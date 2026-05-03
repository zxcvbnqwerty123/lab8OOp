#pragma once
class Property {
protected:
    unsigned int worth;
public:
    Property(unsigned int w) : worth(w) {}
    virtual ~Property() {}
    virtual double calculateTax() = 0;
    double calculateIncomeTax() {
        return worth * 0.13;
    }
    unsigned int getWorth() const { return worth; }
};

