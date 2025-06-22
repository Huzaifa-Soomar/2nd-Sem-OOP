#include <iostream>
using namespace std;
const int MAX_Project = 10;

class Project
{
public:
    string title;

    Project(string t) : title(t) {}

    string getTitle()
    {
        return title;
    }
};

class Freelancer
{
    Project *project[MAX_Project];

public:
    string name;
    Freelancer(string n) : name(n) {}
    int count = 0;
    void addProject(Project *p)
    {
        bool alreadyExist = false;
        for (int i = 0; i < count; i++)
        {
            if (project[i] == p)
            {
                alreadyExist = true;
                break;
            }
        }
        if (alreadyExist)
        {
            cout << p->getTitle() << " is already assigned to " << name << endl;
        }
        else
        {
            if (count < MAX_Project)
            {
                project[count++] = p;
            }
            else
            {
                cout << "Project limit reached \n";
            }
        }
    }
    void lisProjects()
    {
        cout << "Name: " << name << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "Project " << i + 1 << ": " << project[i]->getTitle() << endl;
        }
    }
};

int main()
{
    Project p1("e_commerce");
    Project p2("portfolio");
    Project p3("mobile_app");

    Freelancer f("Messi");
    f.addProject(&p1);
    f.addProject(&p2);
    f.addProject(&p3);
    f.addProject(&p3);

    f.lisProjects();
    return 0;
}