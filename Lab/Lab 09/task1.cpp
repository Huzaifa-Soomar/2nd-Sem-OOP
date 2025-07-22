#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator, denominator;
    // Helper function to find GCD
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    // Helper function to simplify fraction
    void simplify()
    {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den)
    {
        if (denominator == 0)
        {
            cout << "Error: Denominator cannot be zero!" << endl;
            denominator = 1;
        }
        simplify();
    }
    // TODO: Implement these operators
    // Fraction operator+(const Fraction& other) const;
    // Fraction operator-(const Fraction& other) const;
    // Fraction operator*(const Fraction& other) const;
    // Fraction operator/(const Fraction& other) const;
    // bool operator==(const Fraction& other) const;

    Fraction operator+(const Fraction &other) const
    {
       int num = numerator * other.denominator + other.numerator * denominator;
       int den = denominator * other.denominator;
       return Fraction(num , den);
    }
    Fraction operator-(const Fraction &other) const
    {
        int num = numerator * other.denominator - other.numerator * denominator;
       int den = denominator * other.denominator;
       return Fraction(num , den);
    }
    Fraction operator*(const Fraction& other) const
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
    Fraction operator/(const Fraction& other) const
    {
        if (other.numerator == 0)
        {
            cout << "Error : Division by zero \n";
            return Fraction(0, 1);
        }

        return (numerator * other.denominator, denominator * other.numerator );
    }
    bool operator==(const Fraction &other) const
    {
        return (numerator == other.numerator && denominator == other.denominator);
    }
    void display() const
    {
        cout  << numerator << " / "<< denominator << endl;
    }
};

int main()
{
    Fraction f1(2 , 5) , f2(3 , 5);

    Fraction sum = f1 + f2;
    Fraction diff = f1 - f2;
    Fraction mult = f1 * f2;
    Fraction div = f1 / f2;

    cout << "SUM: " ;  sum.display(); cout << endl ;
    cout << "Difference: " ;  diff.display(); cout << endl ;
    cout << "Product: " ;  mult.display(); cout << endl ;
    cout << "Division: " ;  div.display(); cout << endl ;
    return 0;
}