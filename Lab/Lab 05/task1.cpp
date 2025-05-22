#include <iostream>
using namespace std;

bool isPalindrome(string str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

bool isPalindrome(int number)
{
    string str = to_string(number);
    return isPalindrome(str);
}

int main()
{
    cout << boolalpha;
    int n;
    string str;
    cout << "Enter a string to check if it's a palindrome: ";
    cin >> str;
    cout << "Is '" << str << "' a palindrome? " << isPalindrome(str) << endl;

    cout << "Enter a number to check if it's a palindrome: ";
    cin >> n;
    cout << "Is '" << n << "' a palindrome? " << isPalindrome(n) << endl;

    return 0;
}