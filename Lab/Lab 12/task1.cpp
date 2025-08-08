#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Book
{
public:
    string isbn, author, title;

    Book(string isbn, string title, string author)
        : isbn(isbn), title(title), author(author) {}

    void print()
    {
        cout << "ISBN: " << isbn << " | Author: " << author << " | Title: " << title << "\n";
    }
};

int search(unordered_map<string , Book> & library , string author , multimap<string , Book>& searchResult)
{
	int noOfBooks  = 0;
	
	for(pair<string , Book> i : library)
	{
		if(i.second.author == author)
		{
			noOfBooks++;
			searchResult.insert({author , i.second});
		}
	}
	return noOfBooks;
}

int main()
{
    unordered_map<string, Book> library;
    library.insert({"9635280258938", Book("9635280258938", "Mercury", "Asad")});
    library.insert({"8417392305289", Book("8417392305289", "Earth", "Asad")});
    library.insert({"4323267170016", Book("4323267170016", "Mars", "Taimoor")});
    library.insert({"8951093252041", Book("8951093252041", "Saturn", "Unknown")});
    library.insert({"5580166798252", Book("5580166798252", "Jupiter", "Taimoor")});
    library.insert({"4702599831795", Book("4702599831795", "Venus", "Asad")});
         
    for (pair<string, Book> i : library)
    {
        //i.second.print();
    }
    
    multimap <string ,Book> searchResult;
    
    search(library , "Taimoor" , searchResult);   
    
    for(pair<string , Book> i : searchResult)
    {
    	i.second.print();
	}

    return 0;
}
