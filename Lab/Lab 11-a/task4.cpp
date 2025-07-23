#include <iostream>
using namespace std;

int main()
{
    int x, y, opt;

    cout << "Enter 1st number: ";
    cin >> x;

    cout << "Enter 2nd number: ";
    cin >> y;

    do
    {
        cout << "\nSelect Operation:\n";
        cout << "1. +\n2. -\n3. x\n4. /\n";
        cin >> opt;

        try
        {
            switch (opt)
            {
            case 1:
                cout << "Sum: " << x + y << endl;
                opt = 0; 
                break;
            case 2:
                cout << "Difference: " << x - y << endl;
                opt = 0;
                break;
            case 3:
                cout << "Product: " << x * y << endl;
                opt = 0;
                break;
            case 4:
                if (y == 0)
                    throw "Cannot divide by zero!";
                cout << "Division: " << x / y << endl;
                opt = 0;
                break;
            default:
                cout << "Invalid option selected!\n";
            }
        }
        catch (const char *msg)
        {
            cout << "Exception: " << msg << endl;
            cout << "Please re-enter 2nd number: ";
            cin >> y;
        }

    } while (opt != 0);

    return 0;
}
