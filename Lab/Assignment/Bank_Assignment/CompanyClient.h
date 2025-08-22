#ifndef COMPANYCLIENT_H
#define COMPANYCLIENT_H

#include "User.h"
#include "UserClient.h"

class CompanyClient : public User {
private:
    UserClient* employees;
    int empCount;
    int empCapacity;

public:
    CompanyClient();
    CompanyClient(string n, string c, string p, string e, string a,
                  string accType, string accNo, double bal, string pinCode);
    ~CompanyClient();

    void addEmployee(UserClient emp);
    void save();
};

#endif

