#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class IEncryptable
{
public:
    virtual void encrypt(string plainText) = 0;
    virtual void decrypt(string cipherText) = 0;
};

class ROT13 : public IEncryptable
{
public:
    void encrypt(string plainText) override
    {
        string result = "";
        for (int i = 0; i < plainText.length(); i++)
        {
            char c = plainText[i];
            if (isalpha(c))
            {
                char base = islower(c) ? 'a' : 'A';
                c = (c - base + 13) % 26 + base;
            }
            result += c;
        }
        cout << "ROT13 Encrypted: " << result << endl;
    }

    void decrypt(string cipherText) override
    {
        encrypt(cipherText);
    }
};


// With the help of GPT
class RandomCipher : public IEncryptable
{
private:
    char original[62];
    char shuffled[62];

    void generateShuffledArray()
    {
        int index = 0;
        for (char c = 'A'; c <= 'Z'; ++c)
            original[index++] = c;
        for (char c = 'a'; c <= 'z'; ++c)
            original[index++] = c;
        for (char c = '0'; c <= '9'; ++c)
            original[index++] = c;

        for (int i = 0; i < 62; i++)
            shuffled[i] = original[i];

        srand(time(0));
        for (int i = 61; i > 0; --i)
        {
            int j = rand() % (i + 1);
            swap(shuffled[i], shuffled[j]);
        }
    }

    int findIndex(char arr[], char c)
    {
        for (int i = 0; i < 62; i++)
        {
            if (arr[i] == c)
                return i;
        }
        return -1;
    }

public:
    RandomCipher()
    {
        generateShuffledArray();
    }

    void encrypt(string plainText) override
    {
        string result = "";
        for (int i = 0; i < plainText.length(); i++)
        {
            char c = plainText[i];
            int index = findIndex(original, c);
            if (index != -1)
                result += shuffled[index];
            else
                result += c;
        }
        cout << "RandomCipher Encrypted: " << result << endl;
    }

    void decrypt(string cipherText) override
    {
        string result = "";
        for (int i = 0; i < cipherText.length(); i++)
        {
            char c = cipherText[i];
            int index = findIndex(shuffled, c);
            if (index != -1)
                result += original[index];
            else
                result += c;
        }
        cout << "RandomCipher Decrypted: " << result << endl;
    }
};

int main()
{
    IEncryptable *r1 = new ROT13();
    r1->encrypt("Hello123");
    r1->decrypt("Uryyb123");

    cout << endl;

    IEncryptable *r2 = new RandomCipher();
    r2->encrypt("Hello123");

    string encryptedText;
    cout << "Enter the encrypted text from above to decrypt: ";
    cin >> encryptedText;
    r2->decrypt(encryptedText);

    delete r1;
    delete r2;
    return 0;
}
