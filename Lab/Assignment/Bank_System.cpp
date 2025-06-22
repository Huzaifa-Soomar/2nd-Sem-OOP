#include <iostream>
#include <fstream>
using namespace std;

class UserClient
{
public:
    string name, cnic, address, password, loginID, acc_type;
    long long ph;
    double balance;

    void Register()
    {
        cout << "Name : \n";
        cin >> name;
        cout << "CNIC : \n";
        cin >> cnic;
        if (cnic.length() > 13)
        {

            cout << "Kindly , Input again! \n";
            cin >> cnic;
        }
        else if (cnic.length() < 13)
        {
            cout << "Kindly , Input again! \n";
            cin >> cnic;
        }

        cout << "Address : \n";
        cin >> address;
        cout << "Phone No : \n";
        cin >> ph;
        cout << "Login ID : \n";
        cin >> loginID;
        cout << "Password : \n";
        cin >> password;
        cout << "Account Type : \n";
        cin >> acc_type;
        balance = 0;
    }

    void SaveToFile()
    {
        ofstream outFile("users.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << "1, " << name << ", " << cnic << ", " << address << ", "
                    << ph << ", " << loginID << ", " << password << ", "
                    << acc_type << ", " << balance << "\n";
            outFile.close();
        }
        else
        {
            cout << "Unable to open users.txt" << endl;
        }
    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposit successful. New balance : " << balance << endl;
    }
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficent funds \n";
        }
        else
        {
            balance -= amount;
            cout << "Withdrawl successful. New balance: " << balance << endl;
        }
    }
    void showBalance()
    {
        cout << "Current Balance: " << balance << endl;
    }

    void showTransactionHistory(int userID)
    {
        ifstream inFile("transactions.txt");
        string line;
        while (getline(inFile, line))
        {
            if (line.find(to_string(userID)) != string::npos)
            {
                cout << line << endl;
            }
        }
        inFile.close();
    }
    
};

int main()
{
    return 0;
}