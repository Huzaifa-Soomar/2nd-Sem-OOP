#include<iostream>
using namespace std;

class PaymentGateway{
    public:
    virtual bool pay(double amount) = 0;
};

class StripeGateway : public PaymentGateway{
    public:
    bool pay(double amount) override{
        if (amount > 1000)
        {
            cout << "Payment of $" << amount  <<  " using Stripe: Failed \n";
            return false;
        }else{
            cout << "Payment of $" << amount  <<  " using Stripe: Success \n";
            return true;
        }
        
    }

};

class PayPalGateway : public PaymentGateway{
    public:
    bool pay(double amount) override{
        if (amount < 10)
        {
            cout << "Payment of $" << amount  <<  " using PayPal: Failed \n";
             return false;
        }else{
            cout << "Payment of $" << amount  <<  " using PayPal: Success \n";
             return true;
        }
        
    }

};

class CryptoGateway : public PaymentGateway{
    public:
    bool pay(double amount) override{
        cout << "Payment of $" << amount  <<  " using Crypto: Success \n";
        return true;
    }

};

int main()
{
    PaymentGateway* pg;

    pg = new StripeGateway();
    pg->pay(800); 

    pg = new PayPalGateway();
    pg->pay(5); 

    pg = new CryptoGateway();
    pg->pay(1000);

    return 0;
}
