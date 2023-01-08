#include <iostream>
using namespace std;

int i = 0;
int j = i + 1;

// sort using Nontail recursion.
void sortNonTail(int* arr, int n){
	
    if (i == n-1) {
        return;
    }
    else {
        if (j == n - 1) {
            j = 0;
            i++;
            sortNonTail(arr, n);
        }
        if (arr[j] > arr[i]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

        }
        j++;
        sortNonTail(arr, n);       
    }
    cout << arr[i]; // printing just to make in non tail
}

int* sortTail(int* arr, int n) {
	
    if (i == n ) {
        return 0;
    }
    else {
        if (j == n - 1) {
            j = 0;
            i++;
            return sortTail(arr, n);
        }
        if (arr[j] > arr[i]) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			
        }
        j++;
        return sortTail(arr, n);
    }
}
int main() {
    int* arr, n;
    cout << "Enter the number of elements: ";
    cin >> n;
    arr = new int[n];
    cout << "Enter element : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sortNonTail(arr, n);
    cout << endl;
    for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
    }
	
}
