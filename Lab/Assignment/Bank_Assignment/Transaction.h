#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction {
private:
    string date;
    string sourceAcc;
    double amount;
    string type;
    string targetAcc;
public:
    Transaction();
    Transaction(const string &date, const string &source, double amt, const string &type, const string &target = "");

    void saveToFile(const string &filename = "data/transactions.txt") const;
    static void displayForAccount(const string &accNo, const string &filename = "data/transactions.txt");
};

#endif

