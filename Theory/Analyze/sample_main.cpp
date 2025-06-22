#include "Speeding.h"
#include "Officer.h"
#include "Vehicle.h"
#include "Citizen.h"
#include "Ticket.h"

int main()
{
    ViolationType *v1 = new Speeding();
    Officer o1(101, "Ali");
    Vehicle v("ABC-123", "PK123456789", "Car");
    Citizen c1("Sana", "CNIC-XYZ", "0300-1234567");

    Ticket t1(v1, &o1, &c1, &v);
    t1.viewDetails();

    return 0;
}
