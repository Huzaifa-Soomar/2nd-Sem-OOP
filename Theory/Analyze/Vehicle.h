#include <string>
using namespace std;

class Vehicle {
private:
    string plateNumber;
    string registration;
    string type;
public:
    Vehicle(string p, string r, string t) : plateNumber(p), registration(r), type(t) {}
    string getPlate() { return plateNumber; }
};
