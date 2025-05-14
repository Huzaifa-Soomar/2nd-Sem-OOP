#include <iostream>
using namespace std;

class TimedCounter
{
private:
    int counter;
    int maxLimit;
    float restinterval;

public:
    TimedCounter(int c, int ml, float ri)
    {
        counter = c;
        maxLimit = ml;
        restinterval = ri;
        if (maxLimit < 1)
        {
            maxLimit = 10;
        }
    }
    int getMl()
    {
        return maxLimit;
    }
    int getCounter()
    {
        return counter;
    }
    void increment()
    {
        if (counter < maxLimit)
        {
            counter++;
        }
    }

    void ResetIfDue(int secondsElapsed){
        if(secondsElapsed >= restinterval){
            counter =0;
        }
    }

};

int main()
{
    TimedCounter tc(10 , 30 , 40.5);
    cout << "Initial Counter : " << tc.getCounter() << endl;
    tc.increment();
    cout << "After Increment : " << tc.getCounter() << endl;
    tc.ResetIfDue(40.6);
    cout << "After reset check : " << tc.getCounter() << endl;

    return 0;
}