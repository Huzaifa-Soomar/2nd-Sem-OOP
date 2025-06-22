#include <iostream>
using namespace std;

class Product
{
public:
    string name;
    float price;

    Product(string n, float p) : name(n), price(p) {}

    string getName()
    {
        return name;
    }

    float getPrice()
    {
        return price;
    }
};

class CartItem
{
    Product *product;

public:
    int quantity;

    CartItem()
    {
        product = nullptr;
        quantity = 0;
    }

    void setItem(Product *p, int q)
    {
        product = p;
        quantity = q;
    }

    float getTotalPrice() const
    {
        return product->getPrice() * quantity;
    }

    void display() const
    {
        cout << product->getName() << "        $" << product->getPrice()
             << "    " << quantity
             << "           $" << getTotalPrice() << endl;
    }
};

class Cart
{
    CartItem items[100];

public:
    int itemCount = 0;

    void addItem(Product *p, int qty)
    {
        if (itemCount >= 100)
        {
            cout << "Your cart is full\n";
            return;
        }
        items[itemCount].setItem(p, qty);
        itemCount++;
    }

    void showCart()
    {
        cout << "Items       Price   Quantity    Total" << endl;
        cout << "-----------------------------------------" << endl;

        for (int i = 0; i < itemCount; i++)
        {
            items[i].display();
        }

        cout << "-----------------------------------------" << endl;
        float total = calculateTotal();

        cout << "Total cart cost :   $" << total << endl;
    }

    float calculateTotal()
    {
        float total = 0;
        for (int i = 0; i < itemCount; i++)
        {
            total += items[i].getTotalPrice();
        }
        return total;
    }
};

int main()
{
    Product p1("PS 5", 300);
    Product p2("PS 4", 500);
    Product p3("PS 3", 100);

    Cart basket;
    basket.addItem(&p1, 3);
    basket.addItem(&p2, 5);
    basket.addItem(&p3, 5);

    basket.showCart();

    return 0;
}
