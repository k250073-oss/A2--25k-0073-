#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    int year;
    float mileage;
    float conditionScore;

public:
    Vehicle(string b, string m, int y, float mil)
        : brand(b), model(m), year(y), mileage(mil), conditionScore(10.0) {}
    
    virtual ~Vehicle() {}
    
    virtual void displayDetails() const = 0; 

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    float getMileage() const { return mileage; }
    void updateMileage(float addedMiles) { mileage += addedMiles; }

    bool operator==(const Vehicle& other) const;

    friend void verifyVehicleInspection(const class Admin& a, Vehicle& v);
};

#endif