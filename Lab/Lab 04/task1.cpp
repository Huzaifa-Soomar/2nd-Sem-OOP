#include <iostream>
using namespace std;

class Employee
{
private:
    int salary;

public:
    string name;
    int age;

public:
    void work()
    {
        cout << "Working" << endl;
    }
};

class Manager : public Employee
{
public:
    void conductMeeting()
    {
        cout << "Conducting meeting" << endl;
    }
};

class Developer : public Employee
{
public:
    void writecode()
    {
        cout << "write coding" << endl;
    }
};

int main()
{
    Manager m;
    m.work();
    m.conductMeeting();

    Developer d;
    d.work();
    d.writecode();
    return 0;
}