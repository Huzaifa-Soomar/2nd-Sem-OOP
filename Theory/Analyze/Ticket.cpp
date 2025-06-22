#include "ViolationType.h"
#include "Vehicle.h"
#include "Officer.h"
#include "Citizen.h"

class Ticket {
private:
    string ticketID;
    time_t timestamp;
    time_t dueDate;
    ViolationType* violation;
    Officer* officer;
    Citizen* citizen;
    Vehicle* vehicle;
    bool isPaid = false;
public:
    Ticket(ViolationType* v, Officer* o, Citizen* c, Vehicle* ve);
    void viewDetails();
    string getID() { return ticketID; }
};