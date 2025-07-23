#include <iostream>
using namespace std;

template <typename T>
void BubbleSort(T arr[], int size) {
    for (int i = 0; i < size-1 ; i++)
    {
        for (int j = 0; j < size -i-1 ; j++)
        {
            if (arr[j] > arr[j+1])
        {
            swap(arr[j] ,arr[j+1]);
        }
        }
                
    }
    

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {
    int intArr[] = {5, 3, 8, 9, 2, 15, 16};
    double doubleArr[] = {3.3, 1.1, 2.2};
    char charArr[] = {'z', 'c', 'a', 'b'};

    BubbleSort(intArr, 7);       
    BubbleSort(doubleArr, 3);    
    BubbleSort(charArr, 4);      

    return 0;
}

