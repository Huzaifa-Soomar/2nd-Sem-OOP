#include<iostream>
using namespace std;

class Item{
    public:
    string name;
    int price;

    Item (string n , int p){
        name = n;
        price = p;
    }


};

class FoodItem : public Item{

    public:
    FoodItem(string n , int p) : Item(n ,p){}
    
    public:
    int calculateDiscount(){
        cout << "Apply 20% discount on   " << name <<  endl;
        return price  - (price* 0.20);
    }

};

class NonFoodItem : public Item{

    public:
    NonFoodItem(string n , int p) : Item(n ,p){}
    
    public:
    float applyTax(){
        if (price > 50){
            cout << "Apply 10% tax on   "  <<  name << endl;
            return price + (price * 0.10);
        }else{
            cout << "No Tax apply on " <<  name<< endl;
        }
    }

};



int main()
{
    NonFoodItem Ni("Shoes" , 150);
    int aT = Ni.applyTax();
    cout << "Price After Tax : " << aT << endl;

    FoodItem Fi("Falsa" , 100);
    int cD =  Fi.calculateDiscount();
    cout << "Discounted Price : " << cD << endl;
    
    
    return 0;
}