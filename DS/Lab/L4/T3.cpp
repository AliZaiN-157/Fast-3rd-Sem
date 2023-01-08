#include <iostream>
using namespace std;

void insertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i;
		int temp = a[i];
		while (j > 0 && temp < a[j - 1]) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
}

int main() {
	int a[] = { 11, 2, 9, 13, 57, 25, 17, 1, 90, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	insertionSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}