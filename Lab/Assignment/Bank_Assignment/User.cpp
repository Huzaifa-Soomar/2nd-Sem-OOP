#include "User.h"
#include <iostream>
#include <fstream>
using namespace std;

User::User() {
    balance = 0.0;
}

User::User(string n, string c, string p, string e, string a,
           string accType, string accNo, double bal, string pinCode) {
    name = n;
    cnic = c;
    phone = p;
    email = e;
    address = a;
    accountType = accType;
    accountNumber = accNo;
    balance = bal;
    pin = pinCode;
}

string User::getAccountNumber() const {
    return accountNumber;
}

string User::getName() const {
    return name;
}

double User::getBalance() const {
    return balance;
}

bool User::verifyPin(string enteredPin) const {
    return (enteredPin == pin);
}

void User::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        saveTransaction("Deposit", amount);
        cout << "? Deposit successful. New Balance: " << balance << "\n";
    } else {
        cout << "? Invalid deposit amount.\n";
    }
}

void User::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        saveTransaction("Withdraw", amount);
        cout << "? Withdrawal successful. New Balance: " << balance << "\n";
    } else {
        cout << "? Insufficient balance or invalid amount.\n";
    }
}

void User::saveTransaction(string type, double amount, string targetAcc) {
    ofstream file("data/transactions.txt", ios::app);
    if (file.is_open()) {
        file << accountNumber << "," << type << "," << amount;
        if (!targetAcc.empty()) file << ",To:" << targetAcc;
        file << "\n";
        file.close();
    }
}

void User::saveToFile(string fileName) {
    ofstream file(fileName, ios::app);
    if (file.is_open()) {
        file << name << "," << cnic << "," << phone << "," << email << ","
             << address << "," << accountType << "," << accountNumber << ","
             << balance << "," << pin << "\n";
        file.close();
    }
}

