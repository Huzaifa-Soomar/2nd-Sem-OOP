#include<iostream>
#include <cstring>
using namespace std;

class Resume{
    char* name;
    char* skills;
public:
    Resume(){
        name = nullptr;
        skills = nullptr;
    }
    Resume( const char* n , const char* s){
        name  = new char[strlen(n) + 1];
        strcpy(name , n);

        skills = new char[strlen(s) + 1];
        strcpy(skills ,s);
    }
    Resume(const Resume& other){
        name  = new char[strlen(other.name) + 1];
        strcpy(name , other.name);

        skills = new char[strlen(other.skills) + 1];
        strcpy(skills ,other.skills);
    }
    ~Resume(){
        delete[] name;
        delete[] skills;
    }

    void modify(const char* n , const char* s){
        delete [] name;
        delete [] skills;


        name  = new char[strlen(n)  +1];
        strcpy(name , n);

        skills = new char[strlen(s) + 1];
        strcpy(skills , s);
    }

    void display(){
        cout << "Name: " << name << endl;
        cout << "Skills: " << skills << endl;
    }  


};



int main()
{
    Resume r1("Huzaifa" , "Product Manager");
    Resume r2 = r1;

    r1.modify("Soomar" , "Senior Manager");

    r1.display();
    r2.display();


    return 0;
}