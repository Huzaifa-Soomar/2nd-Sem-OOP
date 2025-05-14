#include <iostream>
using namespace std;

class Parcel
{
private:
    string parcelID;

protected:
    float kg;

public:
    Parcel(string pID, float kilo)
    {
        parcelID = pID;
        kg = kilo;
    }

    string getParacelID()
    {
        return parcelID;
    }
};

class TimedParcel : public Parcel
{
protected:
    float deliverySpeed;

public:
    TimedParcel(float ds, string parcelID, float kg) : Parcel(parcelID, kg)
    {
        deliverySpeed = ds;
    }

    float getEstimatedTime(float distance)
    {
        float time;
        time = distance / deliverySpeed;
        return time;
    }
};

class InternationalParcel : public TimedParcel
{

public:
    float customDelay;

    InternationalParcel(float cd, float ds, string parcelID, float kg) : TimedParcel(ds, parcelID, kg)
    {
        customDelay = cd;
    }

    float GetTotalDeliveryTime(float distance)
    {
        return (getEstimatedTime(distance) + customDelay);
    }
};

int main()
{
    InternationalParcel ip(23.5 ,29.5, "ABGDH@##@" , 5.7 );
    
    string a = ip.getParacelID();
    cout << "Parcel ID : " << a << endl;

    float c  = ip.getEstimatedTime(12.45);
    cout << "Total Delivery time " << c << "hours" << endl;




    return 0;
}