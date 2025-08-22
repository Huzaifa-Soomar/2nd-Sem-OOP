#include "UserClient.h"

UserClient::UserClient() : User() {}

UserClient::UserClient(string n, string c, string p, string e, string a,
                       string accType, string accNo, double bal, string pinCode)
    : User(n, c, p, e, a, accType, accNo, bal, pinCode) {}

void UserClient::save() {
    saveToFile("data/users.txt");
}

