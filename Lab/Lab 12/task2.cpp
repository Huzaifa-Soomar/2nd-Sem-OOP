#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;

class Student
{
    string name;
    string rollNum;

public:
    Student(string n, string r) : name(n), rollNum(r) {};

    bool operator<(const Student &other) const
    {
        string roll1 = rollNum;
        string roll2 = other.rollNum;

        for (int i = 0; i < roll1.length(); i++)
        {
            if (roll1[i] >= 'A' && roll1[i] <= 'Z')
            {
                roll1[i] = roll1[i] + 32; // +32 means it convert captal to small (in ASCII)
            }
        }
        for (int i = 0; i < roll2.length(); i++)
        {
            if (roll2[i] >= 'A' && roll2[i] <= 'Z')
            {
                roll2[i] = roll2[i] + 32; // +32 means it convert captal to small (in ASCII)
            }
        }

        return roll1 < roll2;
    }

    void print() const {
    cout << "Roll No: " << rollNum << ", Name: " << name << endl;
}

   


};

int main()
{
     ifstream inputFile("students.txt");

     if (!inputFile)
     {
        cout << "File openeing error \n";
        return 1;
     }

     set<Student> students;
     string line;

     while (getline(inputFile , line))
     {
        string rollNum = "" , name = "";
        int i = 0;

        while (line[i] != ',' &&  i < line.length())
        {
            rollNum += line[i];
            i++;
        }
        i++; // commas skip

        while (i < line.length() && line[i] != ',')
        {
            name += line[i];
            i++;
        }

        students.insert(Student(name , rollNum));

        
        
     }

     inputFile.close();

     for(const Student&s : students)
     {
        s.print();
     }
     
     
    return 0;
}