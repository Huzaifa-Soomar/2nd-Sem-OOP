#include<iostream>
#include<string>
using namespace std;

class User{
    public:
    string name;
    int userId;
    public:

    User(string n , int id) : name(n) ,userId(id) {}

    virtual void displayProfile() = 0;

    virtual string getRole() = 0;
   
};

class Employer : public User{
    public:
    string CompanyName;
    int jobPost;
    public:

    Employer(string cn , int jb ,string n , int id  ) : User(name , id){
        CompanyName = cn;
        jobPost = jb;
    }

    string getRole() override{
        return "Employer\n";
    }

    void displayProfile() override{
        cout << " Employee Name : " << name << endl;
        cout << "Company Name : " << CompanyName << endl;
        cout << "Total job post : " << jobPost << endl;
        
    }

};

class Applicant : public User {
    public:
    string resumeTitle;
    int appliedJobs;

    Applicant(string rt , int aj, string n , int id) : User(name , id){
        resumeTitle = rt;
        appliedJobs = aj;
    }

    string getRole() override{
        return "Applicant\n";
    }

     void displayProfile() override{
        cout << " Applicant Name : " << name << endl;
        cout << "Resume Title : " << resumeTitle << endl;
        cout << "Applied Job : " << appliedJobs << endl;
    }

};
int main()
{
    User * user ;

    user = new Employer("Google" , 2 , "David" , 7);
    //user->getRole();
    user->displayProfile();

    user = new Applicant("Front_end Dev" , 5 , "Babar" , 5);
    //user ->getRole();
    user ->displayProfile();


    return 0;
}