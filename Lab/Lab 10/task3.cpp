#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair
{
private:
    T1 a;
    T2 b;

public:
    Pair(T1 x, T2 y) : a(x), b(y) {}
    void swap()
    {
        T2 temp = a;
        a = b;
        b = temp;
    }
    void display()
    {
        cout << "a: " << a << ", b: " << b << endl;
    }
};
int main()
{
    Pair<float, int> p(22.45, 19);

    cout << "Before swap: ";
    p.display();

    p.swap();

    cout << "After swap: ";
    p.display();

    return 0;
}