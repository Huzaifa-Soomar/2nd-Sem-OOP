#include <string>
#include <vector>
#include "Ticket.h"

using namespace std;

// class Ticket;

class Citizen
{
private:
    string name;
    string cnic;
    string phone;
    vector<Ticket *> tickets;

public:
    Citizen(string n, string c, string p) : name(n), cnic(c), phone(p) {}
    void addTicket(Ticket *t) { tickets.push_back(t); }
    void viewTickets()
    {
        for (auto t : tickets)
        {
            t->viewDetails();
        }
    }
};
