
#include <iostream>
#include <string>

using namespace std;

class Item
{
protected:
    int productId;
    string name;

public:
    Item(int id, string n) : productId(id), name(n) {}
    virtual void display() const = 0;

    int getProductId() const
    {
        return productId;
    }
    string getName() const
    {
        return name;
    }
};

class Product : public Item
{
private:
    int day, month, year;
    double cost;

public:
    Product(int id, const string &n, int d, int m, int y, double c)
        : Item(id, n), day(d), month(m), year(y), cost(c) {}

    int getDay() const
    {
        return day;
    }
    int getMonth() const
    {
        return month;
    }
    int getYear() const
    {
        return year;
    }
    double getCost() const
    {
        return cost;
    }

    
    void display() const override
    {

        cout << productId << "                 " << day << "/" << month << "/" << year << "                 " << cost << "          " << name << endl;
    }
};


int main()
{
    Item *items[5];
    items[0] = new Product(8, "minipizza", 5, 7, 2025, 500);
    items[1] = new Product(2, "cupcake", 3, 7, 2025, 250);
    items[2] = new Product(5, "cupcake", 3, 7, 2025, 200);
    items[3] = new Product(5, "cocopowder", 3, 7, 2025, 200);
    items[4] = new Product(5, "chocolate", 3, 7, 2025, 340);

     cout << "---------------------------------------------------------------------" << endl;
    cout << "Product ID:       Expiry Date       Cost: (Rs)       Name" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for (int i = 0; i < 5; ++i)
    {
        items[i]->display();
    }



    return 0;
}
