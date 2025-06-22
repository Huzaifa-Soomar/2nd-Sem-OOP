#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// Abstract Base Class
class ViolationType {
protected:
    string name;
    double baseFine;
public:
    virtual double calculateFine() = 0; // Pure virtual method
    string getName() { return name; }
};

// Concrete Subclasses
class Speeding : public ViolationType {
public:
    Speeding() { name = "Speeding"; baseFine = 1500; }
    double calculateFine() override {
        return baseFine + (baseFine * 0.1); // Optional dynamic logic
    }
};

class NoHelmet : public ViolationType {
public:
    NoHelmet() { name = "No Helmet"; baseFine = 1000; }
    double calculateFine() override {
        return baseFine;
    }
};

class ParkingViolation : public ViolationType {
public:
    ParkingViolation() { name = "Parking"; baseFine = 500; }
    double calculateFine() override {
        return baseFine;
    }
};

// Core Classes
class Vehicle {
private:
    string plateNumber;
    string registration;
    string type;
public:
    Vehicle(string p, string r, string t) : plateNumber(p), registration(r), type(t) {}
    string getPlate() { return plateNumber; }
};

class Officer {
private:
    int badgeNumber;
    string name;
public:
    Officer(int b, string n) : badgeNumber(b), name(n) {}
    void issueTicket(Citizen&, ViolationType*, Vehicle*);
};

class Citizen {
private:
    string name;
    string cnic;
    string phone;
    vector<class Ticket*> tickets;
public:
    void addTicket(class Ticket* t) { tickets.push_back(t); }
    void viewTickets() {
        for (auto t : tickets) {
            t->viewDetails();
        }
    }
};

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
    Ticket(ViolationType* v, Officer* o, Citizen* c, Vehicle* ve) 
        : violation(v), officer(o), citizen(c), vehicle(ve) {
        ticketID = "T" + to_string(rand() % 10000);
        time(&timestamp);
        dueDate = timestamp + 15 * 24 * 3600; // 15-day grace period
    }

    void viewDetails() {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Violation: " << violation->getName() << endl;
        cout << "Due Date: " << ctime(&dueDate);
        cout << "Fine: Rs." << violation->calculateFine() << endl;
    }

    string getID() { return ticketID; }
};

// Optional: Add Payment, Dispute, and Reporting modules