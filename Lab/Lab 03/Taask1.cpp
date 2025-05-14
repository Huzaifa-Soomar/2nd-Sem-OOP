#include<iostream>
using namespace std;

class Book{
    public:
    string title;
    string author;
    int year;

    Book(){
        title = "Unknown";
        author = "Unknown";
        year = 0;
    }

    void display(){
        cout << title << endl;
        cout << author << endl;
        cout << year << endl;
    }



};
int main()
{
    Book book1;
    book1.display();
    return 0;
}