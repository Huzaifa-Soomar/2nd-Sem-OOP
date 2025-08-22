#include "Admin.h"

Admin::Admin() : adminID("admin"), password("admin123") {}

Admin::Admin(string id, string pass) : adminID(id), password(pass) {}

bool Admin::login(const string &id, const string &pass) const {
    return (id == adminID && pass == password);
}

string Admin::getAdminID() const {
    return adminID;
}

