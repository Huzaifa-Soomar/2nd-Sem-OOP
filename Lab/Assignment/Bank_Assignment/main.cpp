#include <iostream>
#include <string>
#include "Bank.h"
#include "Utility.h"
#include "Card.h"

using namespace std;

int main() {
    Bank bank;

    bank.loadUsers("data/users.txt");
    bank.loadCompanies("data/companies.txt");
    bank.loadCards("data/cards.txt");

    int choice = -1;
    do {
        cout << "\n=== GuTech Bank Management ===\n";
        cout << "1. Register User Client\n";
        cout << "2. Register Company Client\n";
        cout << "3. User Login (by account number)\n";
        cout << "4. Company Login (by account number)\n";
        cout << "5. Create Card for Account\n";
        cout << "6. Admin Login\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore();
            string name, cnic, phone, email, address, accType;
            double initBal;
            cout << "Full name: "; getline(cin, name);
            cout << "CNIC (13 digits): "; getline(cin, cnic);
            cout << "Phone (11 digits): "; getline(cin, phone);
            cout << "Address: "; getline(cin, address);
            cout << "Login ID (use as account type label): "; getline(cin, accType);
            cout << "Initial deposit: "; cin >> initBal;
            string accNo = generateAccountNumber();
            string pin = generatePin();
            UserClient* u = new UserClient(name, cnic, phone, email, address, accType, accNo, initBal, pin);
            bank.addUser(u);
            cout << "Account created. Account No: " << accNo << " PIN: " << pin << "\n";
        }
        else if (choice == 2) {
            cin.ignore();
            string name, cnic, phone, email, address, accType;
            double initBal;
            cout << "Company name: "; getline(cin, name);
            cout << "Tax number / Owner CNIC: "; getline(cin, cnic);
            cout << "Phone: "; getline(cin, phone);
            cout << "Address: "; getline(cin, address);
            cout << "Account type label: "; getline(cin, accType);
            cout << "Initial deposit: "; cin >> initBal;
            string accNo = generateAccountNumber();
            string pin = generatePin();
            CompanyClient* c = new CompanyClient(name, cnic, phone, email, address, accType, accNo, initBal, pin);
            bank.addCompany(c);
            cout << "Company account created. Account No: " << accNo << " PIN: " << pin << "\n";
        }
        else if (choice == 3) {
            string accNo; cout << "Account number: "; cin >> accNo;
            UserClient* u = bank.findUserByAccount(accNo);
            if (!u) { cout << "Not found.\n"; continue; }
            bank.userMenu(u);
        }
        else if (choice == 4) {
            string accNo; cout << "Company account number: "; cin >> accNo;
            CompanyClient* c = bank.findCompanyByAccount(accNo);
            if (!c) { cout << "Not found.\n"; continue; }
            bank.companyMenu(c);
        }
        else if (choice == 5) {
            string accNo; cout << "Account number to create card for: "; cin >> accNo;
            if (!bank.findUserByAccount(accNo) && !bank.findCompanyByAccount(accNo)) {
                cout << "Account not found.\n"; continue;
            }
            unsigned long long cardNo = generateCardNumber();
            int pin = generateCardPin();
            Card* card = new Card(accNo, cardNo, pin);
            bank.addCard(card);
            cout << "Card created: " << card->cardNumberToString() << " PIN: " << pin << "\n";
        }
        else if (choice == 6) {
            string id, pass; cout << "Admin ID: "; cin >> id; cout << "Password: "; cin >> pass;
            if (bank.getAdmin().login(id, pass)) {
                cout << "Admin logged in.\n";
                int adminChoice = -1;
                do {
                    cout << "\nAdmin Menu:\n1. View all users\n2. View all companies\n3. View all transactions\n0. Logout\nChoice: ";
                    cin >> adminChoice;
                    if (adminChoice == 1) bank.viewAllUsers();
                    else if (adminChoice == 2) bank.viewAllCompanies();
                    else if (adminChoice == 3) bank.viewAllTransactions();
                } while (adminChoice != 0);
            } else cout << "Invalid admin credentials.\n";
        }

    } while (choice != 0);

    cout << "Goodbye.\n";
    return 0;
}

