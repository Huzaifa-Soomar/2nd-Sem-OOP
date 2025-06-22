#include<iostream>
using namespace std;

class Light{
    public:
    bool isOn = false;
    void lightOn(){
        isOn = true;
    }
    void lightOff(){
        isOn = false;
    }
    string getStatus(){
        if (isOn)
        {
            return "Light is on\n";
        }else{
            return "Light is off\n";
        }
        
    }
};

class Thermostat{
    public:
    float temp;
    void setTemperature(float temp ){
        this->temp = temp;
    }
    float getTemperature()const{
        return temp;
    }

};
class SmartHome{
    Light light;
    Thermostat thermostat;
    public:
    void statusReport(string place_name) {
        cout << "status report for " << place_name << endl;
        light.lightOn();
        thermostat.setTemperature(22.5);
        cout << light.getStatus();
        cout << "current temperature : " << thermostat.getTemperature() << " °C\n";
        
    }
};


int main()
{
    SmartHome sh1 , sh2;
    sh1.statusReport("Kitchen");
    sh2.statusReport("Bed Room");
    return 0;
}