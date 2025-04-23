#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
    void carInfo(string brand, string model, int year)
    {
        cout << "Car Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{  
    Car car1, car2;
    car1.carInfo("Toyota", "Corolla", 2020);
    car2.carInfo("Honda", "Civic", 2022);
    return 0;
}