#include <iostream>
using namespace std;

class Body
{
    public:
    void relatHeart(){
        cout << "Body has a heart \n";
    }
    void relatBrain(){
        cout << "Body contains brain \n";
    }
};

class Heart
{
    Body *body;
};
class Brain
{
public:
    Body body;
};

int main()
{
    Body body;
    body.relatBrain();
    body.relatHeart();

    return 0;
}