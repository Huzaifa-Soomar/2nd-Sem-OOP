#ifndef ADMIN_H
#define ADMIN_H

#include <string>
using namespace std;

class Admin {
private:
    string adminID;
    string password;
public:
    Admin();
    Admin(string id, string pass);

    bool login(const string &id, const string &pass) const;
    string getAdminID() const;
};

#endif

