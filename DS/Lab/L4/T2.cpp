#include <iostream>
using namespace std;

class Date
{
public:
		
	int day;
	int month;
	int year;
};

void swap(Date* a, Date* b)
{
	Date temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(Date arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j].year < arr[min_idx].year)
				min_idx = j;

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}

// Function to print an array
void printArray(Date arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i].day << " " << arr[i].month << " " << arr[i].year << endl;
	cout << endl;
}

// Driver program to test above functions
int main()
{
	Date arr[5];
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter day month and year" << endl;
		cin >> arr[i].day >> arr[i].month >> arr[i].year;
	}
	selectionSort(arr, n);
	cout << "Sorted array: n";
	printArray(arr, n);
	return 0;
}