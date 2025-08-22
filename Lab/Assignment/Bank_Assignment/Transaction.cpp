#include "Transaction.h"
#include <fstream>
#include <iostream>

Transaction::Transaction() : date(""), sourceAcc(""), amount(0.0), type(""), targetAcc("") {}

Transaction::Transaction(const string &d, const string &source, double amt, const string &t, const string &target)
    : date(d), sourceAcc(source), amount(amt), type(t), targetAcc(target) {}

void Transaction::saveToFile(const string &filename) const {
    ofstream file(filename, ios::app);
    if (!file) return;
    if (targetAcc.empty())
        file << date << "," << sourceAcc << "," << amount << "," << type << "\n";
    else
        file << date << "," << sourceAcc << "," << amount << "," << type << "," << targetAcc << "\n";
    file.close();
}

void Transaction::displayForAccount(const string &accNo, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No transactions file found.\n";
        return;
    }
    string line;
    cout << "Transactions for account " << accNo << ":\n";
    bool any = false;
    while (getline(file, line)) {
        if (line.find(accNo) != string::npos) {
            cout << line << "\n";
            any = true;
        }
    }
    if (!any) cout << "No transactions found.\n";
    file.close();
}

