

#include <iostream>
using namespace std;

class CryptoExchange
{
public:
    double balance = 1500;
    virtual void buyCrypto(double amount) = 0;
    virtual void sellCrypto(double amount) = 0;
    virtual void accBalance() = 0;
    virtual double calcTradingFees(double amount) = 0;
    virtual string getName() = 0;
};

class BinanceExchange : public CryptoExchange
{
public:
 
  void buyCrypto(double amount) override {
    double fee = calcTradingFees( amount);
    double totalCost = amount + fee;

    if (balance >=totalCost)
    {
        balance -=totalCost;
        cout << "[Binance] Bought crypto worth $" << amount << " with fee $" << fee << endl;
    }else{
        cout << "[Binance] Insufficient balance to buy $" << amount << " of crypto \n";
    }
    
  }

  void sellCrypto(double amount) override {
    double fee = calcTradingFees(amount);
    balance += (amount - fee);
    cout << "[Binance] Sold crypto worth $" << amount << " with fee $" << fee << endl;

  }

  void accBalance() override{
    cout << "[Binance] Current Balance: $" << balance << endl;

  }

  double calcTradingFees(double amount) override{
    return amount * 0.01;

  }

  string getName() override {
    return "Binance";
  }

  
  
};

class CoinBaseExchange : public CryptoExchange
{
    public:
    void buyCrypto(double amount) override{
        double fee = calcTradingFees(amount);
        double totalCost = amount + fee;

        if (balance >= totalCost)
        {
            balance -= totalCost;
            cout << "[CoinBase] Bought crypto worth $" << amount << " with fee $" << fee << endl;
        }else{
           cout << "[CoinBase] Insufficient balance to buy $" << amount << " of crypto \n"; 
        }
        
    }

    void sellCrypto(double amount) override {
        double fee = calcTradingFees(amount);
        balance += (amount - fee);
        cout << "[CoinBase] Sold crypto worth $" << amount << " with fee $" << fee << endl; 
    }

    void accBalance() override {
        cout << "[CoinBase] current Blance $: " << balance << endl;
    }

   double calcTradingFees(double amount) override{
    return amount *0.025;
   }
   
   string getName() override{
    return "Coin Base";
   }
};

class PortfolioManager{

    public:
    CryptoExchange *ex1;
    CryptoExchange *ex2;

    void showBalance(){
        ex1->accBalance();
        ex2->accBalance();
    }

    void performTrades(){
        cout << "\n--- Performing Trades ---\n";
        ex1 ->buyCrypto(200);
        ex2 ->sellCrypto(300);
        ex1 ->buyCrypto(2000);
        ex2 ->sellCrypto(1000);
    }

};

int main()
{
    BinanceExchange binance;
    CoinBaseExchange coinbase;
    PortfolioManager Pm;
    Pm.ex1 = &binance;
    Pm.ex2 = &coinbase;

    cout << "...... Initial Balances .....\n";
    Pm.showBalance();

    Pm.performTrades();

    cout << ".........Final Balances ............\n";
    Pm.showBalance();
    


    return 0;
}