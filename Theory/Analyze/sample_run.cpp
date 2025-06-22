
int main()
{
    ViolationType *v1 = new Speeding();
    Officer o1(101, "Ali");
    Vehicle v("ABC-123", "PK123456789", "Car");
    Citizen c1("Sana", "CNIC-XYZ", "0300-1234567");

    Ticket *t1 = new Ticket(v1, &o1, &c1, &v);
    t1->viewDetails();

    return 0;
}

// Output:
// Ticket ID: T1234
// Violation: Speeding
// Due Date: 2025-04-15
// Fine: Rs.1650