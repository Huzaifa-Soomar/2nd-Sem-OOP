#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class ViolationType;
class Officer;
class Citizen;
class Vehicle;

class Ticket
{
private:
    string ticketID;
    time_t timestamp;
    time_t dueDate;
    ViolationType *violation;
    Officer *officer;
    Citizen *citizen;
    Vehicle *vehicle;
    bool isPaid = false;

public:
    Ticket(ViolationType *v, Officer *o, Citizen *c, Vehicle *ve)
        : violation(v), officer(o), citizen(c), vehicle(ve)
    {
        ticketID = "T" + to_string(rand() % 10000);
        time(&timestamp);
        dueDate = timestamp + 15 * 24 * 3600;
    }

    void viewDetails()
    {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Violation: " << violation->getName() << endl;
        cout << "Due Date: " << ctime(&dueDate);
        cout << "Fine: Rs." << violation->calculateFine() << endl;
    }
};
