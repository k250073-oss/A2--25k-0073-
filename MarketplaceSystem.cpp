#include "MarketplaceSystem.h"

int Listing::totalListingsCreated = 0;

bool Vehicle::operator==(const Vehicle& other) const {
    return (this->brand == other.brand && this->model == other.model && this->year == other.year);
}

void Car::displayDetails() const {
    cout << "[Car] " << year << " " << brand << " " << model << " | " << mileage << "km | " << transmissionType << " | Type: " << bodyType << " | Doors: " << numDoors << endl;
}

void Bike::displayDetails() const {
    cout << "[Bike] " << year << " " << brand << " " << model << " | " << mileage << "km | " << (hasKickstart ? "Kick-Start" : "Self-Start") << " | " << bikeType << " frame" << endl;
}

void Truck::displayDetails() const {
    cout << "[Truck] " << year << " " << brand << " " << model << " | Hauling Cap: " << loadCapacityTonnes << " Tons | Axles: " << axlesCount << endl;
}

void DirectMessage::displayMessage() const {
    cout << "[" << timestamp << "] DM from " << senderName << " to " << receiverName << ": \"" << content << "\"" << (isRead ? " (Read)" : " (Unread)") << endl;
}

void Seller::displayProfile() const {
    cout << "--- Seller Profile: " << name << " | Dealer Shop: " << shopName << " | Rating: " << sellerRating << "/5.0 ---" << endl;
}
void Seller::receiveMessage(const DirectMessage& msg) {
    cout << ">> Notification to Seller [" << name << "]:" << endl;
    msg.displayMessage();
}

void Buyer::displayProfile() const {
    cout << "--- Buyer Profile: " << name << " | Available Allocation: PKR " << maxBudget << " ---" << endl;
}
void Buyer::saveFavorite(Listing* lst) {
    if (favCount < 10) {
        favorites[favCount++] = lst;
        cout << ">> " << name << " added listing ID " << lst->getId() << " to favorites collection." << endl;
    }
}
void Buyer::viewFavorites() const {
    cout << "\n================ " << name << "'s Handpicked Favorites ================" << endl;
    for (int i = 0; i < favCount; i++) {
        favorites[i]->displayListing();
    }
}
void Buyer::sendMessage(Seller* sellerObj, string text) {
    DirectMessage msg(501, this->name, sellerObj->getName(), text, "10:15 PM");
    sellerObj->receiveMessage(msg);
}

void Admin::displayProfile() const {
    cout << "--- Admin Executive Profile: " << name << " | Clearance Level: " << clearanceCode << " ---" << endl;
}
void Admin::approveListing(Listing& lst) {
    lst.setStatus("Approved");
    actionsTaken++;
    cout << ">> Admin [" << name << "] processed approval on verification asset: " << lst.getId() << endl;
}
void Admin::removeListing(Listing& lst) {
    lst.setStatus("Removed");
    actionsTaken++;
    cout << ">> Admin [" << name << "] rejected listing item code: " << lst.getId() << endl;
}

void Listing::displayListing() const {
    cout << "Ad Code: " << listingId << " [" << status << "] | Listing Price: PKR " << price << endl;
    if (vehicle) {
        cout << "   Asset Information: ";
        vehicle->displayDetails();
    }
    cout << "   Registered Dealer: " << (seller ? seller->getName() : "Unknown Base") << " | Processing Duty (5%): PKR " << calculateTax() << endl;
}
double Listing::calculateTax() const {
    return price * 0.05; 
}
bool Listing::operator<(const Listing& other) const {
    return this->price < other.price;
}

ostream& operator<<(ostream& os, const Listing& l) {
    os << "[Listing Code: " << l.listingId << " | " << (l.vehicle ? l.vehicle->getBrand() : "N/A") << " | Price: PKR " << l.price << "]";
    return os;
}

bool checkBuyerBudget(const Buyer& b, const Listing& l) {
    return b.maxBudget >= l.price; 
}

void verifyVehicleInspection(const Admin& a, Vehicle& v) {
    cout << ">> Audit Pass: Inspector " << a.name << " [" << a.clearanceCode << "] verified structural score: " << v.conditionScore << "/10.0" << endl;
}

Marketplace& Marketplace::operator+(const Listing& lst) {
    if (currentListingCount < 100) {
        platformListings[currentListingCount++] = lst;
        cout << ">> System Log: Listing ID " << lst.getId() << " inserted natively via operator+ into " << platformName << endl;
    }
    return *this;
}

void Marketplace::searchListingsByBrand(string brand) const {
    cout << "\n~~~~ Standard Query: Matching Models for '" << brand << "' ~~~~" << endl;
    for (int i = 0; i < currentListingCount; i++) {
        if (platformListings[i].getVehicle() && platformListings[i].getVehicle()->getBrand() == brand) {
            platformListings[i].displayListing();
        }
    }
}

void Marketplace::searchListingsByBrand(string brand, double maxPrice) const {
    cout << "\n~~~~ Budget Query: Models for '" << brand << "' Under PKR " << maxPrice << " ~~~~" << endl;
    for (int i = 0; i < currentListingCount; i++) {
        if (platformListings[i].getVehicle() && platformListings[i].getVehicle()->getBrand() == brand && platformListings[i].getPrice() <= maxPrice) {
            platformListings[i].displayListing();
        }
    }
}

void Marketplace::updateListingPrice(int id, double newPrice) {
    for (int i = 0; i < currentListingCount; i++) {
        if (platformListings[i].getId() == id) {
            platformListings[i].setPrice(newPrice);
            cout << ">> Notification: Listing ID " << id << " updated price to PKR " << newPrice << endl;
            return;
        }
    }
}