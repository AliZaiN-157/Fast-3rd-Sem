#include <iostream>

using namespace std;


// Write a program that will read 10 integers from the keyboard and place them in an array. The
// program then will sort the array into ascendingand descending orderand print the sorted list using pointers.
// The program must not change the original array or not create any other integer arrays.


int main() {

    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;
    int* arr = new int[size];
    int* newArr = new int[size];
    int count = 0;


    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    for (int i = 0, j = 0, k = size - 1; i < size/2; i++) {

        count++;
        newArr[2*i] = arr[k];
        k--;
        newArr[2 * i + 1] = arr[j];
    }
    cout << "Count: " << count << endl;

    for (int i = 0; i < size; i++) {
        cout << newArr[i] << " ";
    }
}
















