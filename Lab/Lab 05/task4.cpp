#include<iostream>
using namespace std;

class Character{
    public:
    double health;

};

class Attacker{
    public:

    virtual void  attack() = 0;

};

class Defender{
    public:

    virtual void  defend() = 0;
    

};

class MagicUser{
    public:
    virtual void castSpell() = 0;
};

class Paladin : public Character , public Attacker, public Defender, public MagicUser{

    public:

    void attack () override {
        cout << "Paladin attack \n";

    }

    void defend() override{
        cout << "Paladin defend \n";
    }

    void castSpell() override {
        cout << "Paladin use magic \n";
    }
};  


int main()
{
    Paladin p;
    cout << "Monster defend \n";
    p.attack();
    cout << "Monster attack \n";
    int n = p.health = 90;
    cout << "Paladin health : " << n << endl;
    p.castSpell();
    p.defend();

    return 0;
}