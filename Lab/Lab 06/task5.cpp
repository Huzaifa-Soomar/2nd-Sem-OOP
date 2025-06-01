#include<iostream>
using namespace std;

class IEncryptable{
    public:
    virtual void encrypt(string plainText) = 0;
    virtual void decrypt(string cipherText) = 0;

};

class ROT13 : public IEncryptable {
    public:
    void encrypt(string plainText) override{

    }

    void decrypt(string cipherText) override{

    }
};

class RandomCipher : public IEncryptable {
    public:
    void encrypt(string plainText) override{

    }

    void decrypt(string cipherText) override{
        
    }
};


int main()
{
    return 0;
}