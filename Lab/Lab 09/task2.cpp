#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    // TODO: Implement these operators
    // Complex operator+(const Complex& other) const;
    // Complex operator-(const Complex& other) const;
    // Complex operator*(const Complex& other) const;
    // bool operator==(const Complex& other) const;
    // friend ostream& operator<<(ostream& os, const Complex& c);

    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }
    Complex operator*(const Complex &other) const
    {
        double r = real * other.real - imag * other.imag;
        double i = real * other.real - imag * other.imag;
        return Complex(r, i);
    }
    bool operator==(const Complex &other) const
    {
        return (real == other.real, imag == other.imag);
    }
    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << c.real;
        if (c.imag >= 0)
        {
            os << " + " << c.imag << "i";
        }
        else
        {
            os << " - " << c.imag << "i";
        }

        return os;
    }

    double magnitude() const
    {
        return sqrt(real * real + imag * imag);
    }
};

int main()
{
    Complex c1(3, 4), c2(1, -2);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;

    if (c1 == c2)
        cout << "c1 and c2 are equal" << endl;
    else
        cout << "c1 and c2 are not equal" << endl;
    return 0;
}