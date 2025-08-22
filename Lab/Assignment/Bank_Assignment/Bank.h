#ifndef BANK_H
#define BANK_H

#include "UserClient.h"
#include "CompanyClient.h"
#include "Card.h"
#include "Transaction.h"
#include "Admin.h"
#include <string>

class Bank {
private:
    UserClient** users;
    int userCount;
    int userCapacity;

    CompanyClient** companies;
    int companyCount;
    int companyCapacity;

    Card** cards;
    int cardCount;
    int cardCapacity;

    Admin admin;

    // internal helpers
    void ensureUserCapacity();
    void ensureCompanyCapacity();
    void ensureCardCapacity();

public:
    Bank();
    ~Bank();

    void loadUsers(const std::string &filename = "data/users.txt");
    void loadCompanies(const std::string &filename = "data/companies.txt");
    void loadCards(const std::string &filename = "data/cards.txt");

    void addUser(UserClient* user);
    void addCompany(CompanyClient* comp);
    void addCard(Card* card);

    UserClient* findUserByAccount(const std::string &accNo) const;
    CompanyClient* findCompanyByAccount(const std::string &accNo) const;

    void userMenu(UserClient* user);
    void companyMenu(CompanyClient* comp);

    const Admin& getAdmin() const { return admin; }
    void viewAllUsers() const;
    void viewAllCompanies() const;
    void viewAllTransactions() const;
};

#endif

