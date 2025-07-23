#include <iostream>
using namespace std;

template <typename T>
T calculate(T a, T b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b != 0) return a / b;
            else {
                cout << "Error: Division by zero!" << endl;
                return 0;
            }
        default:
            cout << "Error: Invalid operator!" << endl;
            return 0;
    }
}

int main() {
    char op;
    double num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    double result = calculate(num1, num2, op);

    cout << "Result: " << result << endl;

    return 0;
}
