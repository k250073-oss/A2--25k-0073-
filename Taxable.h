#ifndef TAXABLE_H
#define TAXABLE_H

class Taxable {
public:
    virtual ~Taxable() {}
    virtual double calculateTax() const = 0; 
};

#endif