#include <iostream>
#include <cstring>
using namespace std;

class Address
{
    char *city;

public:
    Address()
    {
        city = nullptr;
    }
    Address(const char *c)
    {
        city = new char[strlen(c) + 1];
        strcpy(city, c);
    }
    Address(const Address &other)
    {
        city = new char[strlen(other.city) + 1];
        strcpy(city, other.city);
    }
    ~Address()
    {
        delete[] city;
    }
    void modify(const char *c)
    {
        delete[] city;
        city = new char[strlen(c) + 1];
        strcpy(city, c);
    }
    void display()
    {
        cout << "City: " << city << endl;
    }
};

class Person
{
    char *name;
    Address address;

public:
    Person()
    {
        name = nullptr;
        address = nullptr;
    }
    Person(const char *n, const char *c) : address(c)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    Person(const Person &other) : address(other.address)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    ~Person()
    {
        delete[] name;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        address.display();
    }

    void modify(const char *n, const char *c)
    {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        address.modify(c);
    }
};

int main()
{
    Person p1("Huzaifa", "Karachi");
    Person p2 = p1;

    cout << "...........Before modifying..........." << endl;
    p1.display();
    p2.display();

    cout << "..........After modifying............" << endl;
    p1.modify("Abdullah", "Lahore");
    p1.display();
    p2.display();

    return 0;
}