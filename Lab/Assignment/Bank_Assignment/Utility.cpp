#include "Utility.h"
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>

static bool seeded = false;
static void seedOnce() {
    if (!seeded) {
        srand((unsigned)time(NULL));
        seeded = true;
    }
}

string generateAccountNumber() {
    seedOnce();
    stringstream ss;
    ss << "AC";
    for (int i = 0; i < 8; ++i) ss << (rand() % 10);
    return ss.str();
}

string generatePin() {
    seedOnce();
    int val = rand() % 9000 + 1000;
    stringstream ss; ss << setw(4) << setfill('0') << val;
    return ss.str();
}

unsigned long long generateCardNumber() {
    seedOnce();
    unsigned long long num = 0;
    for (int i = 0; i < 4; ++i) {
        int block = rand() % 9000 + 1000;
        num = num * 10000ULL + (unsigned long long)block;
    }
    return num;
}

int generateCardPin() {
    seedOnce();
    return rand() % 9000 + 1000;
}

string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buf[11];
    snprintf(buf, sizeof(buf), "%02d-%02d-%04d", ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
    return string(buf);
}

