#include<iostream>
using namespace std;

class Employe {
    private:
    int salary;
    public:
    string name;
    string position;

    public:
    Employe(){
        name = "Huzaifa";
        position = "Senior Dev";
        salary = 23000;

    }

    Employe(string n  ,string p ,int s){
        name  = n;
        position = p;
        salary = s;
    }

    void printInfo(){
        cout << name << endl;
        cout << position << endl;
        cout <<  salary << endl;
    }



};

int main()
{
    Employe e1 ;
    cout << "..............Default const..............."<< endl;
    e1.printInfo();

    cout << "..............Parameter const..............."<< endl;
    Employe e2("Soomar" , "PM" , 980000);
    e2.printInfo();

    return 0;
}