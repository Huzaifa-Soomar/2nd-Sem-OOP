#include <string>
using namespace std;

class Citizen; // forward declaration
class ViolationType;
class Vehicle;

class Officer {
private:
    int badgeNumber;
    string name;
public:
    Officer(int b, string n) : badgeNumber(b), name(n) {}
    void issueTicket(Citizen&, ViolationType*, Vehicle*) {}
};
