// Abstract Base Class
class ViolationType {
protected:
    string name;
    double baseFine;
public:
    virtual double calculateFine() = 0; // Pure virtual method
    string getName() { return name; }
};