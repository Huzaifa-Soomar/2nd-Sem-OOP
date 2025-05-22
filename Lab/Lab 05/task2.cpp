#include <iostream>
using namespace std;
class Printer
{
public:
    void printer()
    {

        cout << "Printing.......\n";
    }
};
class Scanner
{
public:
    void scanner()
    {

        cout << "Scanning....\n";
    }
};
class Copier : public Printer, public Scanner
{
public:
    void copier()
    {

        scanner();
        printer();
    }
};

int main()
{
    Copier c;
    c.copier();
    return 0;
}