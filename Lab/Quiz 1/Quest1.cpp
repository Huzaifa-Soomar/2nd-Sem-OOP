#include<iostream>
using namespace std;

class SecureSensor{
    public:
    int id;
    int sensitivityLevel;
    SecureSensor(int ID  ,int sl ){
        id = ID;
        sensitivityLevel = sl;
    }

    private:
    int lastReading ;

    public:
    float RecordReading(float newValue , int arr[10]){
        

    }



    

};


int main()
{
    return 0;
}