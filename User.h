#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    int userId;
    string name;
    string email;
    string phone;
    string accountStatus;

public:
    User(int id, string n, string e, string p)
        : userId(id), name(n), email(e), phone(p), accountStatus("Active") {}
    
    virtual ~User() {}
    
    virtual void displayProfile() const = 0; 

    string getName() const { return name; }
    void suspendAccount() { accountStatus = "Suspended"; }
    void activateAccount() { accountStatus = "Active"; }
};

#endif