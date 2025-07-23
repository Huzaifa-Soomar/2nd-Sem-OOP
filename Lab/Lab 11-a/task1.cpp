#include <iostream>
#include <stdexcept>
using namespace std;

void test(int value) {
       if (value < 0)
        throw "Negative numbers are not allowed! ";
}
int main() {
   try {
    int n;
    cout << "Enter a positive number: ";
    cin >> n;
    test(n);
    }
    catch (const char* msg) {
       cout << " Exception: " << msg << endl;
    }
return 0;
}
