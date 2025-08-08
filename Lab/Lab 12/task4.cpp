#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
public:
    vector<double> coeff; // coeff[i] = coefficient for x^i

    Polynomial(vector<double> c) : coeff(c) {}
    Polynomial() {}

    // Addition
    Polynomial operator+(const Polynomial& other) const {
        vector<double> res(max(coeff.size(), other.coeff.size()), 0);
        for (size_t i = 0; i < res.size(); i++) {
            if (i < coeff.size()) res[i] += coeff[i];
            if (i < other.coeff.size()) res[i] += other.coeff[i];
        }
        return Polynomial(res);
    }

    // Subtraction
    Polynomial operator-(const Polynomial& other) const {
        vector<double> res(max(coeff.size(), other.coeff.size()), 0);
        for (size_t i = 0; i < res.size(); i++) {
            if (i < coeff.size()) res[i] += coeff[i];
            if (i < other.coeff.size()) res[i] -= other.coeff[i];
        }
        return Polynomial(res);
    }

    // Multiplication
    Polynomial operator*(const Polynomial& other) const {
        vector<double> res(coeff.size() + other.coeff.size() - 1, 0);
        for (size_t i = 0; i < coeff.size(); i++) {
            for (size_t j = 0; j < other.coeff.size(); j++) {
                res[i + j] += coeff[i] * other.coeff[j];
            }
        }
        return Polynomial(res);
    }

    // Division (basic long division)
    Polynomial operator/(const Polynomial& other) const {
        vector<double> a = coeff; // copy dividend
        vector<double> q(a.size(), 0); // quotient
        int degA = a.size() - 1;
        int degB = other.coeff.size() - 1;

        for (int i = degA - degB; i >= 0; i--) {
            q[i] = a[i + degB] / other.coeff[degB];
            for (int j = 0; j <= degB; j++) {
                a[i + j] -= q[i] * other.coeff[j];
            }
        }
        return Polynomial(q);
    }

    // Print
    void print() const {
        bool first = true;
        for (int i = coeff.size() - 1; i >= 0; i--) {
            if (coeff[i] != 0) {
                if (!first) cout << " + ";
                cout << coeff[i];
                if (i > 0) cout << "x";
                if (i > 1) cout << "^" << i;
                first = false;
            }
        }
        if (first) cout << "0";
        cout << "\n";
    }
};

int main() {
    Polynomial p1({1, 2, 3}); // 1 + 2x + 3x^2
    Polynomial p2({3, 4});    // 3 + 4x

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;
    Polynomial quot = p1 / p2; // division

    cout << "P1(x) = "; p1.print();
    cout << "P2(x) = "; p2.print();
    cout << "P1 + P2 = "; sum.print();
    cout << "P1 - P2 = "; diff.print();
    cout << "P1 * P2 = "; prod.print();
    cout << "P1 / P2 = "; quot.print();
}
