#include <iostream>
using namespace std;

class ArrayHolder {
    int *arr;
    int arrSize;
public:
    ArrayHolder(int arrSize) {
        this->arrSize = arrSize;
        arr = new int[arrSize];
        cout << "Enter the elements in the array:" << endl;
        for (int i = 0; i < arrSize; i++) {
            cin >> arr[i];
        }
    }

    ArrayHolder() {
        arrSize = 5;
        arr = new int[arrSize];
        cout << "Enter the elements in the array:" << endl;
        for (int i = 0; i < arrSize; i++) {
            cin >> arr[i];
        }
    }

    ArrayHolder(const ArrayHolder& other) {
        arrSize = other.arrSize;
        arr = new int[arrSize];
        for (int i = 0; i < arrSize; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~ArrayHolder() {
        delete[] arr;
        arr = NULL;
    }

    void display() {
        for (int i = 0; i < arrSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayHolder a1(5);
    a1.display();

    ArrayHolder a2 = a1;
    a2.display();

    return 0;
}
 