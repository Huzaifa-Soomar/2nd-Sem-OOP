#include "Card.h"
#include <fstream>
#include <sstream>

Card::Card() : accountNumber(""), cardNumber(0), pin(0) {}

Card::Card(const string &accNo, unsigned long long cardNo, int p)
    : accountNumber(accNo), cardNumber(cardNo), pin(p) {}

unsigned long long Card::getCardNumber() const { return cardNumber; }
int Card::getPin() const { return pin; }
string Card::getAccountNumber() const { return accountNumber; }

void Card::saveToFile(const string &filename) const {
    ofstream file(filename, ios::app);
    if (!file) return;
    file << accountNumber << "," << cardNumber << "," << pin << "\n";
    file.close();
}

string Card::cardNumberToString() const {
    stringstream ss;
    ss << cardNumber;
    return ss.str();
}

