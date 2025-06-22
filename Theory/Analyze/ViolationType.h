#include <string>
using namespace std;

class ViolationType {
protected:
    string name;
    double baseFine;
public:
    virtual double calculateFine() = 0;
    string getName() { return name; }
};
