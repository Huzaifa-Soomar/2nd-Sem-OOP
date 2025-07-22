#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {
private:
    int degree;
    int* arr;

public:
    Polynomial() {
        degree = 0;
        arr = new int[1];
        arr[0] = 0;
    }

    Polynomial(int ar[], int deg) {
        degree = deg;
        arr = new int[degree + 1];
        for (int i = 0; i <= degree; i++) {
            arr[i] = ar[i];
        }
    }

    Polynomial(int deg) {
        degree = deg;
        arr = new int[degree + 1];
        for (int i = 0; i <= degree; i++) arr[i] = 0;
    }

    Polynomial(const Polynomial& other) {
        degree = other.degree;
        arr = new int[degree + 1];
        for (int i = 0; i <= degree; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~Polynomial() {
        delete[] arr;
    }

    Polynomial operator+(const Polynomial& other) const {
        int maxDeg = max(degree, other.degree);
        Polynomial result(maxDeg);
        for (int i = 0; i <= maxDeg; i++) {
            int a = (i <= degree) ? arr[i] : 0;
            int b = (i <= other.degree) ? other.arr[i] : 0;
            result.arr[i] = a + b;
        }
        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        int maxDeg = max(degree, other.degree);
        Polynomial result(maxDeg);
        for (int i = 0; i <= maxDeg; i++) {
            int a = (i <= degree) ? arr[i] : 0;
            int b = (i <= other.degree) ? other.arr[i] : 0;
            result.arr[i] = a - b;
        }
        return result;
    }

    Polynomial operator*(const Polynomial& other) const {
        int newDeg = degree + other.degree;
        Polynomial result(newDeg);
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                result.arr[i + j] += arr[i] * other.arr[j];
            }
        }
        return result;
    }

    int evaluate(int x) const {
        int sum = 0;
        for (int i = 0; i <= degree; i++) {
            sum += arr[i] * pow(x, i);
        }
        return sum;
    }

    void display() const {
        bool firstTerm = true;
        for (int i = degree; i >= 0; i--) {
            if (arr[i] == 0) continue;
            if (!firstTerm) {
                cout << (arr[i] > 0 ? " + " : " - ");
            } else if (arr[i] < 0) {
                cout << "-";
            }
            if (abs(arr[i]) != 1 || i == 0)
                cout << abs(arr[i]);
            if (i > 0)
                cout << "x";
            if (i > 1)
                cout << "^" << i;
            firstTerm = false;
        }
        if (firstTerm) cout << "0";
        cout << endl;
    }

    void printArray() const {
        cout << "Coefficients: ";
        for (int i = 0; i <= degree; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int arr1[4] = {3, 6, 2, -5};
    int arr2[4] = {5, 4, 3, 2};

    Polynomial p1(arr1, 3);
    Polynomial p2(arr2, 3);

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    cout << "p1: ";
    p1.display();
    p1.printArray();

    cout << "p2: ";
    p2.display();
    p2.printArray();

    cout << "p1 + p2: ";
    sum.display();
    sum.printArray();
    cout << "f(2) = " << sum.evaluate(2) << endl;

    cout << "p1 - p2: ";
    diff.display();
    diff.printArray();

    cout << "p1 * p2: ";
    prod.display();
    prod.printArray();

    return 0;
}
