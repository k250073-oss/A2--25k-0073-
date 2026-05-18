#include "MarketplaceSystem.h"

int main() {
    cout << "==========================================================" << endl;
    cout << "   Welcome to PakWheels Advanced Core Architecture v2.0   " << endl;
    cout << "==========================================================\n" << endl;

    Marketplace pakWheels("PakWheels Pakistan");

    Admin leadAdmin(101, "Ali Admin", "ali@pakwheels.pk", "0300-1234567", 5, "PKW-EXECUTIVE-SECURE");
    Seller officialDealer(202, "Ahmed Car Center", "ahmed@autos.pk", "0333-7654321", "Ahmed Corporate Autos", "NTN-9988112");
    Buyer premiumBuyer(303, "Rana Osman", "osman@client.pk", "0321-4445556", 7000000.0);

    Car carAsset("Honda", "Civic Oriel", 2022, 15000, "Automatic", "Sedan", 4);
    Bike bikeAsset("Honda", "CD70", 2023, 2200, true, "Commuter");
    Truck commercialAsset("Isuzu", "NPR Long", 2020, 48000, 5.5, 6);

    verifyVehicleInspection(leadAdmin, carAsset);

    Listing ad1(5001, &carAsset, &officialDealer, 6500000.0);
    Listing ad2(5002, &bikeAsset, &officialDealer, 145000.0);
    Listing ad3(5003, &commercialAsset, &officialDealer, 4800000.0);

    pakWheels + ad1;
    pakWheels + ad2;
    pakWheels + ad3;

    pakWheels.getListingReference(0).setStatus("Approved");
    pakWheels.getListingReference(1).setStatus("Approved");
    pakWheels.getListingReference(2).setStatus("Approved");

    pakWheels.searchListingsByBrand("Honda");
    pakWheels.searchListingsByBrand("Honda", 200000.0); 

    cout << "\n--- Logical Comparison Check ---" << endl;
    if (ad2 < ad1) {
        cout << ">> Pass: Bike Ad price evaluates as strictly less than Car Ad price." << endl;
    }

    cout << ">> Stream Format Dump: " << ad1 << endl;

    cout << "\n--- Financial Affordability Audit Verification ---" << endl;
    if (checkBuyerBudget(premiumBuyer, ad1)) {
        cout << "Affordability validated. Saving item to profile..." << endl;
        premiumBuyer.saveFavorite(&pakWheels.getListingReference(0));
    } else {
        cout << "Warning: Insufficient structural funds for target purchase." << endl;
    }

    premiumBuyer.viewFavorites();

    cout << "\n--- Customer Chat Sequence ---" << endl;
    premiumBuyer.sendMessage(&officialDealer, "Are the registration documents available?");

    return 0;
}