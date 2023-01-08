#include <iostream>

using namespace std;

// Given the following array {35,50,15,25,80,20,90,45}, write a program in C++ that applies quicksort and Radix sort on the array

// partition function
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// quickSort function
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// print array
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 35,50,15,25,80,20,90,45 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Given array is " << endl;
	printArray(arr, n);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: " << endl;
	printArray(arr, n);
	return 0;
}