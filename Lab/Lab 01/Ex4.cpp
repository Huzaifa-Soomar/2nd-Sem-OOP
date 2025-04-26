#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    string title;
    string author;
    int year;
    float price;
    bool isAvailable;

    void getInfo()
    {
        cout << "Book Title : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Year : " << year << endl;
        cout << "Price : $" << price << endl;
        cout << "Availability status : " << (isAvailable ? "Yes" : "NO") << endl;
    }

    void setPrice()
    {
        float newPrice;
        cout << "Enter new price : ";
        cin >> newPrice;
        price = newPrice;
        cout << "New Price : $" << price << endl;
    }
    void toggleAvailability()
    {
        isAvailable = !isAvailable;
        cout << "Availability status change to  : " << (isAvailable ? "Yes" : "NO") << endl;
    }
};

int main()
{
    Book book1, book2, book3;
    book1.title = "PSPF";
    book1.author = "Twaha Minai";
    book1.year = 2025;
    book1.price = 25.99;
    book1.isAvailable = false;

    book2.title = "DM";
    book2.author = "Sir Shehxad";
    book2.year = 2025;
    book2.price = 29.99;
    book2.isAvailable = true;

    book3.title = "DT";
    book3.author = "Sir Rauf";
    book3.year = 2025;
    book3.price = 249.99;
    book3.isAvailable = true;

    cout << "............Book 1 Details..........." << endl;
    book1.getInfo();
    cout << "............Book 2 Details..........." << endl;
    book2.getInfo();
    cout << "............Book 3 Details..........." << endl;
    book3.getInfo();

    string n;
    cout << "If you want to change any book status or price (y/n)" << endl;
    cin >> n;
    if (n == "y")
    {
        int choice;
        cout << "Enter Book Number (1/2/3): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            book1.setPrice();
            book1.toggleAvailability();
            break;
        case 2:
            book2.setPrice();
            book2.toggleAvailability();
            break;
        case 3:
            book3.setPrice();
            book3.toggleAvailability();
            break;        
        default:
        cout << "Inavalid choice :(";
            break;
        }
        cout << "Updated Details " << endl;
        if(choice == 1){
            book1.getInfo();
        }else if (choice ==2)
        {
            book2.getInfo();
        }else{
            book3.getInfo();
        }
        
    }else{
        cout << "Thank you so muvh for visiting our book store :)";
    }

    return 0;
}