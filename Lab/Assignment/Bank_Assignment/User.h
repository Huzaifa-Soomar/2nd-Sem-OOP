#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string name;
    string cnic;
    string phone;
    string email;
    string address;
    string accountType;
    string accountNumber;
    double balance;
    string pin;

public:
    User();
    User(string n, string c, string p, string e, string a,
         string accType, string accNo, double bal, string pinCode);

    string getAccountNumber() const;
    string getName() const;
    double getBalance() const;
    bool verifyPin(string enteredPin) const;

    virtual void deposit(double amount);
    virtual void withdraw(double amount);

    void saveTransaction(string type, double amount, string targetAcc = "");
    void saveToFile(string fileName);
};

#endif

