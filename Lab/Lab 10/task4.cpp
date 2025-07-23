#include <iostream>
#include <string>
#include <utility> 
using namespace std;


template <typename T>
void smartSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


template <>
void smartSort<string>(string arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int intArr[5] = {5, 2, 9, 1, 3};
    float floatArr[4] = {3.2, 1.5, 4.8, 0.9};
    string strArr[4] = {"banana", "apple", "orange", "kiwi"};

    cout << "Original integer array:\n";
    printArray(intArr, 5);
    smartSort(intArr, 5);
    cout << "Sorted integer array:\n";
    printArray(intArr, 5);

    cout << "\nOriginal float array:\n";
    printArray(floatArr, 4);
    smartSort(floatArr, 4);
    cout << "Sorted float array:\n";
    printArray(floatArr, 4);

    cout << "\nOriginal string array:\n";
    printArray(strArr, 4);
    smartSort(strArr, 4);
    cout << "Sorted string array:\n";
    printArray(strArr, 4);

    return 0;
}

