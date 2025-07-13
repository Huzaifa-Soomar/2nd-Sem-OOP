#include <iostream>
#include <cstring>
using namespace std;
class Student
{
    char *name;

public:
    Student(const char *n)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    
    Student(const Student &s)
    {

        name = new char[strlen(s.name) + 1]; 
        strcpy(name , s.name);
    }  
    void display()
    {
        cout << "Name: " << name << endl;
    }
    ~Student()
    {
        delete[] name;
    }
    void update(const char *n){
        delete[] name;

        name = new char[strlen(n) + 1];
        strcpy(name , n);
    }
};

int main()
{
    Student s1("Huziafa");
    Student s2 = s1;
    s1.display();
    s2.display();
    
    s1.update("Soomar");
    s1.display();
    s2.display();
    return 0;
}