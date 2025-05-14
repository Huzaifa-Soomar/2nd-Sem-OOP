#include<iostream>
using namespace std;

class Student {
    private:
    string name;
    int age;
    string grade;
    
    public:
    Student (string n , int a , string g){
        name  = n;
        age  = a;
        grade = g;
    }

    void info(){
        cout << name << endl;
        cout << age << endl;
        cout << grade << endl;
    }

    void setName(string n){
       name  = n;
    }
    string getName(){
        return name;
    }

    void setAge(int a){
       age  = a;
    }
    int getAge(){
        return age;
    }

    void setGrade(string g){
       grade  = g;
    }
    string getGrade(){
        return grade;
    }




};

int main()
{
    Student s1("Huzaifa" , 21 , "A");
    s1.info();

    s1.setName("Soomar");
    string n = s1.getName();
    cout << n << endl;

    s1.setAge(50);
    int a = s1.getAge();
    cout << a << endl;

    s1.setGrade("A+");
    string g = s1.getGrade();
    cout << g << endl;


    return 0;
}