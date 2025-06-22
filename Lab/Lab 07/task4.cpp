#include <iostream>
#include <string>
using namespace std;

class Birthday
{
public:
    int day, year;
    string month;

    Birthday()
    {
        day = 1;
        month = 'Jan';
        year = 2000;
    }
    Birthday(int d, string m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void show() const
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Person
{
    Birthday birthday;

public:
    string name;
    string city;

    Person(string n, string c, Birthday b) : birthday(b)
    {
        name = n;
        city = c;
    };

    void display() const
    {
        cout << "....... Person Details.........\n";
        cout << "Name : " << name << endl;
        cout << "City : " << city << endl;
        cout << "Birthday : ";
        birthday.show();
    }
};

int main()
{
    Person p1("Huzaifa", "Karachi", 30, "September", 2004);
    p1.display();
    return 0;
}