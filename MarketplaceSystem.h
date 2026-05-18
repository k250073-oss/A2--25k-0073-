#ifndef MARKETPLACE_SYSTEM_H
#define MARKETPLACE_SYSTEM_H

#include "Taxable.h"
#include "User.h"
#include "Vehicle.h"
#include "AbstractMessage.h"
#include <iostream>
#include <string>

using namespace std;

class Seller;
class Listing;
class Admin;
class Buyer;

class Address {
private:
    string street, city, state, zipCode, country;
    bool isVerified;
public:
    Address() : street(""), city(""), state(""), zipCode(""), country(""), isVerified(false) {}
    Address(string s, string c, string st, string z, string co)
        : street(s), city(c), state(st), zipCode(z), country(co), isVerified(false) {}
};

class Engine {
private:
    string fuelType;
    int capacityCC, horsepower, cylinders;
    string condition;
    bool isHybrid;
public:
    Engine() : fuelType("Petrol"), capacityCC(1000), horsepower(60), cylinders(3), condition("Good"), isHybrid(false) {}
    Engine(string f, int cc, int hp, int cyl, bool hybrid)
        : fuelType(f), capacityCC(cc), horsepower(hp), cylinders(cyl), condition("Excellent"), isHybrid(hybrid) {}
};

class Car : public Vehicle {
private:
    string transmissionType; 
    string bodyType;         
    int numDoors;
public:
    Car(string b, string m, int y, float mil, string trans, string body, int doors)
        : Vehicle(b, m, y, mil), transmissionType(trans), bodyType(body), numDoors(doors) {}
    
    void displayDetails() const override; 
};

class Bike : public Vehicle {
private:
    bool hasKickstart;
    string bikeType; 
public:
    Bike(string b, string m, int y, float mil, bool kick, string type)
        : Vehicle(b, m, y, mil), hasKickstart(kick), bikeType(type) {}

    void displayDetails() const override;
};

class Truck : public Vehicle {
private:
    double loadCapacityTonnes;
    int axlesCount;
public:
    Truck(string b, string m, int y, float mil, double cap, int axles)
        : Vehicle(b, m, y, mil), loadCapacityTonnes(cap), axlesCount(axles) {}

    void displayDetails() const override;
};

class DirectMessage : public AbstractMessage {
public:
    DirectMessage(int id, string s, string r, string c, string t)
        : AbstractMessage(id, s, r, c, t) {}

    void displayMessage() const override;
};

class Seller : public User {
private:
    int totalListings;
    float sellerRating;
    bool isPremium;
    string shopName, taxId;
public:
    Seller(int id, string n, string e, string p, string shop, string tax)
        : User(id, n, e, p), totalListings(0), sellerRating(5.0), isPremium(false), shopName(shop), taxId(tax) {}

    void displayProfile() const override;
    void receiveMessage(const DirectMessage& msg);
    void incrementListings() { totalListings++; }
};

class Buyer : public User {
private:
    double maxBudget;
    string preferredBrand;
    int favCount;
    Listing* favorites[10];
public:
    Buyer(int id, string n, string e, string p, double budget)
        : User(id, n, e, p), maxBudget(budget), preferredBrand("Any"), favCount(0) {}

    void displayProfile() const override;
    void saveFavorite(Listing* lst);
    void viewFavorites() const;
    void sendMessage(Seller* sellerObj, string text);

    friend bool checkBuyerBudget(const Buyer& b, const Listing& l);
};

class Admin : public User {
private:
    int adminLevel;
    string clearanceCode;
    int actionsTaken;
public:
    Admin(int id, string n, string e, string p, int lvl, string clearance)
        : User(id, n, e, p), adminLevel(lvl), clearanceCode(clearance), actionsTaken(0) {}

    void displayProfile() const override;
    void approveListing(Listing& lst);
    void removeListing(Listing& lst);
    
    friend void verifyVehicleInspection(const Admin& a, Vehicle& v);
};

class Listing : public Taxable {
private:
    int listingId;
    Vehicle* vehicle; 
    Seller* seller;
    double price;
    string status;
public:
    static int totalListingsCreated;

    Listing() : listingId(0), vehicle(nullptr), seller(nullptr), price(0.0), status("Pending") {}
    Listing(int id, Vehicle* v, Seller* s, double p)
        : listingId(id), vehicle(v), seller(s), price(p), status("Pending") {
        totalListingsCreated++;
    }

    int getId() const { return listingId; }
    string getStatus() const { return status; }
    double getPrice() const { return price; }
    Vehicle* getVehicle() const { return vehicle; }
    void setStatus(string s) { status = s; }
    void setPrice(double p) { price = p; }

    void displayListing() const;
    double calculateTax() const override; 

    bool operator<(const Listing& other) const;
    friend ostream& operator<<(ostream& os, const Listing& l);
    friend bool checkBuyerBudget(const Buyer& b, const Listing& l);
};

class Marketplace {
private:
    string platformName;
    Listing platformListings[100];
    int currentListingCount;
public:
    Marketplace(string name) : platformName(name), currentListingCount(0) {}

    void searchListingsByBrand(string brand) const;
    void searchListingsByBrand(string brand, double maxPrice) const;

    void updateListingPrice(int id, double newPrice);
    Listing& getListingReference(int index) { return platformListings[index]; }

    Marketplace& operator+(const Listing& lst);
};

#endif