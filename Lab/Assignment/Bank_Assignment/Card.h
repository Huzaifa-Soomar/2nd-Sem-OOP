#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
private:
    string accountNumber;
    unsigned long long cardNumber;
    int pin;
public:
    Card();
    Card(const string &accNo, unsigned long long cardNo, int pin);

    unsigned long long getCardNumber() const;
    int getPin() const;
    string getAccountNumber() const;
    void saveToFile(const string &filename = "data/cards.txt") const;

    string cardNumberToString() const;
};

#endif

