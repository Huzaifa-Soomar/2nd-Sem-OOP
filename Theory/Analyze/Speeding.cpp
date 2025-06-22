#include "ViolationType.h"

class Speeding : public ViolationType {
public:
    Speeding() { name = "Speeding"; baseFine = 1500; }
    double calculateFine() override {
        return baseFine + (baseFine * 0.1); // 10% surcharge
    }
};