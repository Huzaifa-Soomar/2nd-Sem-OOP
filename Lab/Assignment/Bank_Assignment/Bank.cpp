#include "Bank.h"
#include "Utility.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Bank::Bank() {
    userCapacity = 10; userCount = 0;
    users = new UserClient*[userCapacity];

    companyCapacity = 5; companyCount = 0;
    companies = new CompanyClient*[companyCapacity];

    cardCapacity = 10; cardCount = 0;
    cards = new Card*[cardCapacity];
}

Bank::~Bank() {
    for (int i = 0; i < userCount; ++i) delete users[i];
    delete[] users;
    for (int i = 0; i < companyCount; ++i) delete companies[i];
    delete[] companies;
    for (int i = 0; i < cardCount; ++i) delete cards[i];
    delete[] cards;
}

void Bank::ensureUserCapacity() {
    if (userCount < userCapacity) return;
    int newCap = userCapacity * 2;
    UserClient** tmp = new UserClient*[newCap];
    for (int i = 0; i < userCount; ++i) tmp[i] = users[i];
    delete[] users;
    users = tmp;
    userCapacity = newCap;
}

void Bank::ensureCompanyCapacity() {
    if (companyCount < companyCapacity) return;
    int newCap = companyCapacity * 2;
    CompanyClient** tmp = new CompanyClient*[newCap];
    for (int i = 0; i < companyCount; ++i) tmp[i] = companies[i];
    delete[] companies;
    companies = tmp;
    companyCapacity = newCap;
}

void Bank::ensureCardCapacity() {
    if (cardCount < cardCapacity) return;
    int newCap = cardCapacity * 2;
    Card** tmp = new Card*[newCap];
    for (int i = 0; i < cardCount; ++i) tmp[i] = cards[i];
    delete[] cards;
    cards = tmp;
    cardCapacity = newCap;
}

void Bank::addUser(UserClient* user) {
    ensureUserCapacity();
    users[userCount++] = user;
    user->save();
}

void Bank::addCompany(CompanyClient* comp) {
    ensureCompanyCapacity();
    companies[companyCount++] = comp;
    comp->save();
}

void Bank::addCard(Card* card) {
    ensureCardCapacity();
    cards[cardCount++] = card;
    card->saveToFile();
}

UserClient* Bank::findUserByAccount(const string &accNo) const {
    for (int i = 0; i < userCount; ++i) if (users[i]->getAccountNumber() == accNo) return users[i];
    return nullptr;
}

CompanyClient* Bank::findCompanyByAccount(const string &accNo) const {
    for (int i = 0; i < companyCount; ++i) if (companies[i]->getAccountNumber() == accNo) return companies[i];
    return nullptr;
}

void Bank::loadUsers(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) return;
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string name, cnic, phone, email, address, accType, accNo, balStr, pin;
        getline(ss, name, ',');
        getline(ss, cnic, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, address, ',');
        getline(ss, accType, ',');
        getline(ss, accNo, ',');
        getline(ss, balStr, ',');
        getline(ss, pin, ',');
        double bal = 0; if (!balStr.empty()) bal = stod(balStr);
        UserClient* u = new UserClient(name, cnic, phone, email, address, accType, accNo, bal, pin);
        addUser(u);
    }
    file.close();
}

void Bank::loadCompanies(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) return;
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string name, cnic, phone, email, address, accType, accNo, balStr, pin, empCountStr;
        getline(ss, name, ',');
        getline(ss, cnic, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, address, ',');
        getline(ss, accType, ',');
        getline(ss, accNo, ',');
        getline(ss, balStr, ',');
        getline(ss, pin, ',');
        getline(ss, empCountStr, ',');
        double bal = 0; if (!balStr.empty()) bal = stod(balStr);
        CompanyClient* c = new CompanyClient(name, cnic, phone, email, address, accType, accNo, bal, pin);
        addCompany(c);
    }
    file.close();
}

void Bank::loadCards(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) return;
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string accNo; unsigned long long cardNo; int pin;
        getline(ss, accNo, ',');
        ss >> cardNo;
        if (ss.peek() == ',') ss.get();
        ss >> pin;
        Card* card = new Card(accNo, cardNo, pin);
        addCard(card);
    }
    file.close();
}

void Bank::userMenu(UserClient* user) {
    if (!user) return;
    int choice = -1;
    do {
        cout << "\nUser Menu for " << user->getAccountNumber() << " (" << user->getName() << ")\n";
        cout << "1. Deposit\n2. Withdraw\n3. View Balance\n4. View Transactions\n5. Logout\nChoice: ";
        cin >> choice;
        if (choice == 1) {
            double amt; cout << "Amount: "; cin >> amt;
            user->deposit(amt);
        } else if (choice == 2) {
            double amt; cout << "Amount: "; cin >> amt;
            string pin; cout << "Enter PIN: "; cin >> pin;
            if (user->verifyPin(pin)) user->withdraw(amt);
            else cout << "Invalid PIN.\n";
        } else if (choice == 3) {
            cout << "Balance: " << user->getBalance() << "\n";
        } else if (choice == 4) {
            Transaction::displayForAccount(user->getAccountNumber());
        }
    } while (choice != 5);
}

void Bank::companyMenu(CompanyClient* comp) {
    if (!comp) return;
    int choice = -1;
    do {
        cout << "\nCompany Menu for " << comp->getAccountNumber() << " (" << comp->getName() << ")\n";
        cout << "1. Deposit\n2. Withdraw\n3. Disburse Salaries (simple)\n4. View Balance\n5. View Transactions\n6. Logout\nChoice: ";
        cin >> choice;
        if (choice == 1) {
            double amt; cout << "Amount: "; cin >> amt;
            comp->deposit(amt);
        } else if (choice == 2) {
            double amt; cout << "Amount: "; cin >> amt;
            string pin; cout << "Enter PIN: "; cin >> pin;
            if (comp->verifyPin(pin)) comp->withdraw(amt);
            else cout << "Invalid PIN.\n";
        } else if (choice == 3) {
            double total; cout << "Enter total salary to disburse: "; cin >> total;
            if (total <= comp->getBalance()) {
                comp->withdraw(total);
                Transaction t(getCurrentDate(), comp->getAccountNumber(), total, "SalaryDisburse");
                t.saveToFile();
                cout << "Salaries disbursed.\n";
            } else cout << "Insufficient balance.\n";
        } else if (choice == 4) {
            cout << "Balance: " << comp->getBalance() << "\n";
        } else if (choice == 5) {
            Transaction::displayForAccount(comp->getAccountNumber());
        }
    } while (choice != 6);
}

void Bank::viewAllUsers() const {
    cout << "\n==== All Users ====\n";
    for (int i = 0; i < userCount; ++i) {
        cout << users[i]->getAccountNumber() << " | " << users[i]->getName() << " | Balance: " << users[i]->getBalance() << "\n";
    }
    if (userCount == 0) cout << "No users.\n";
}

void Bank::viewAllCompanies() const {
    cout << "\n==== All Companies ====\n";
    for (int i = 0; i < companyCount; ++i) {
        cout << companies[i]->getAccountNumber() << " | " << companies[i]->getName() << " | Balance: " << companies[i]->getBalance() << "\n";
    }
    if (companyCount == 0) cout << "No companies.\n";
}

void Bank::viewAllTransactions() const {
    cout << "\n==== Transactions (file) ====\n";
    ifstream f("data/transactions.txt");
    if (!f.is_open()) {
        cout << "No transactions file.\n";
        return;
    }
    string line;
    while (getline(f, line)) cout << line << "\n";
    f.close();
}

