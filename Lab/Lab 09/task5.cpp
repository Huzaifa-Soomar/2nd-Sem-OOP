#include <iostream>
using namespace std;

class Teacher; 

class Student {
private:
    string name;

public:
    Student(string n = "") : name(n) {}

    
    friend void printNames(const Student &student, const Teacher &teacher1, const Teacher &teacher2);
};

class Teacher {
private:
    string name;

public:
    Teacher(string n = "") : name(n) {}

    
    friend void printNames(const Student &student, const Teacher &teacher1, const Teacher &teacher2);
};


void printNames(const Student &student, const Teacher &teacher1, const Teacher &teacher2) {
    cout << "Student name: " << student.name << endl;
    cout << "Teacher name: " << teacher1.name << endl;
    cout << "Teacher name: " << teacher2.name << endl;
}

int main() {
    Student s("Huzaifa");
    Teacher t1("Mam Zoha");
    Teacher t2("Sir Taloot");

    printNames(s, t1 , t2);

    return 0;
}
