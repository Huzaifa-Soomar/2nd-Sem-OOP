#include "CompanyClient.h"
#include <iostream>
using namespace std;

CompanyClient::CompanyClient() : User() {
    empCount = 0;
    empCapacity = 2;
    employees = new UserClient[empCapacity];
}

CompanyClient::CompanyClient(string n, string c, string p, string e, string a,
                             string accType, string accNo, double bal, string pinCode)
    : User(n, c, p, e, a, accType, accNo, bal, pinCode) {
    empCount = 0;
    empCapacity = 2;
    employees = new UserClient[empCapacity];
}

CompanyClient::~CompanyClient() {
    delete[] employees;
}

void CompanyClient::addEmployee(UserClient emp) {
    if (empCount >= empCapacity) {
        empCapacity *= 2;
        UserClient* temp = new UserClient[empCapacity];
        for (int i = 0; i < empCount; i++)
            temp[i] = employees[i];
        delete[] employees;
        employees = temp;
    }
    employees[empCount++] = emp;
    emp.save();
}

void CompanyClient::save() {
    saveToFile("data/companies.txt");
}

