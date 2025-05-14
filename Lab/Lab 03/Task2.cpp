#include <iostream>
using namespace std;

class Book
{
public:
    string title;
    string author;
    int year;

public:
    Book(string t, string a, int y)
    {
        title = t;
        author = a;
        year = y;
    }
    void display()
    {
        cout << title << endl;
        cout << author << endl;
        cout << year << endl;
    }
};
int main()
{
    Book book1("Unknown", "Unknown", 0);
    book1.display();

    return 0;
}