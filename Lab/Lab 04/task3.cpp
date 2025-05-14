#include <iostream>
using namespace std;

class Sensor
{
private:
    string id;
    float value;

public:
    Sensor(string i, float v)
    {
        id = i;
        value = v;
    }

    void setValue(float val)
    {
        value = val;
    }

    float getValue()
    {
        return value;
    }

    string getId()
    {
        return id;
    }

protected:
    bool isThresholdExceeded(float threshold)
    {
        return value > threshold;
    }
};

class TemperatureSensor : public Sensor
{
public:
    TemperatureSensor(string i, float v) : Sensor(i, v) {};

    void TriggerAlarm(float threshold)
    {
        if (isThresholdExceeded(threshold))
        {
            cout << "ALERT: " << getId() << " temperature exceeded!" << endl;
        }
    }
};

int main()
{
    TemperatureSensor t("t 128" , 45.67);
    t.setValue(450.78);
    t.TriggerAlarm(98.99);

        return 0;
}