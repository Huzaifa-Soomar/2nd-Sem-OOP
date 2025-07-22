#include <iostream>
using namespace std;

class Time
{
    int hours;
    int min;

public:


    void change(){
        if (min >=60)
        {
            hours += min/60;
            min = min % 60;
        }
        
    }
    Time(int h, int m) : hours(h), min(m) {};

    Time operator+(const Time &other) const
    {
      int total_min = min + other.min;
      int total_hours = hours + other.hours + total_min/60;
      int finalMin = total_min % 60;

      return Time(total_hours , finalMin);
    }

    bool operator==(const Time &other) const
    {
        return (hours == other.hours && min == other.min);
    }
    bool operator!=(const Time &other) const
    {
        return !(*this == other);
    }

    bool operator<(const Time &other) const
    {
        if(hours < other.hours) return true;
        if(hours == other.hours && min < other.min) return true;
        return false;
    }

    bool operator>(const Time &other) const
    {
        if(hours > other.hours) return true;
        if(hours == other.hours && min > other.min) return true;
        return false;
    }

    bool operator<=(const Time &other) const
    {
       return !(*this > other);
    }
    bool operator>=(const Time &other) const
    {
          return !(*this < other);
    }
    Time& operator++() {
        min++;
        change();
        return *this;
    }
    Time& operator--() {
        min--;
        change();
        return *this;
    }

   void display() const {
        cout << "Time: " << hours << " hours " << min << " minutes" << endl;
    }
};

int main() {
    Time t1(2, 45);
    Time t2(1, 30);

    Time sum = t1 + t2;
    sum.display(); 

    ++t1;
    t1.display(); 

    --sum;
    sum.display(); 

    if (t1 < t2)
        cout << "t1 is less than t2\n";
    else
        cout << "t1 is not less than t2\n";

    return 0;
}
