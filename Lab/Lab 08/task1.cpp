#include <iostream>
using namespace std;

class Point{
private:
    int x , y;
public:
    Point(int xc, int yc){
        x = xc;
        y = yc;
    }

    void display(){
        cout << "x point : " << x << endl;
        cout << "y point : " << y << endl;
    }


};

int main(){

    Point p1 (2,5);
    Point p2 = p1;

    p1.display();
    p2.display();


    return 0;
}
