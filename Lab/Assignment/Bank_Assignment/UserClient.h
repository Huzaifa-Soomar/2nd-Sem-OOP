#ifndef USERCLIENT_H
#define USERCLIENT_H

#include "User.h"

class UserClient : public User {
public:
    UserClient();
    UserClient(string n, string c, string p, string e, string a,
               string accType, string accNo, double bal, string pinCode);

    void save();
};

#endif

