#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int age;

    void setName(string n)
    {
        this->name = n;
    }

    void setAge(int a)
    {
        this->age = a;
    }

    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
};

class Student : virtual public Person
{
public:
    void study()
    {
        cout << "Studying...\n";
    }
};

class Teacher : virtual public Person
{

public:
    void teach()
    {
        cout << "teaching...\n";
    }
};

class TeachingAssistant : public Student, public Teacher
{
};

int main()
{
    TeachingAssistant ta;

    ta.setName("Huzaifa");
    string n = ta.getName();

    ta.setAge(21);
    int a = ta.getAge();

    cout << "Name : " << n << endl;

    cout << "Age : " << a << endl;

    ta.study();
    ta.teach();

    return 0;
}