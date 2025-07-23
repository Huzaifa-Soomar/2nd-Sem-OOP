#include <iostream>
using namespace std;

int main()
{
	try{
		int age;
		cout << "Enter Age : ";
		cin >>  age;
		
		if(age < 0)
		{
			throw "Inavlid age \n";
		}else if (age > 150)
		{
		   throw "Unrealistic age entered!\n";	
		}
	}catch (int e) {
         cout << "Integer exception caught: " << e << endl;
    }catch (const char* msg) {
         cout << "String exception caught: " << msg << endl;
		}
	return 0;
}
