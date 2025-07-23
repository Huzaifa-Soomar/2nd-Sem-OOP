#include <iostream>
using namespace std;

int main()
{
	try{
		int arr[5] = {1,2,3,4,5};
		cout << "Array Elements\n";
		for(int i = 0; i <5 ; i++){
			cout << arr[i] << ",";
		}
		cout << endl;
		int idx;
		cout << "Enter Index \n";
		cin >> idx;
		if(idx < 0 || idx > 4){
			throw "Array index out of bounds!";
		}
	}catch (const char*msg){
		cout << " Exception: " << msg    << endl;
	}
	return 0;
}
