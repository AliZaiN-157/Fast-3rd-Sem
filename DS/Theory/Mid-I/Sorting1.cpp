#include <iostream>

using namespace std;

//  Insertion sort goes sequentially through the array when making comparisons to find a proper place 
// for an element currently processed from right to the left of the sorted array. 
// As the input increases this time increases as well, hence making it quite inefficient. 
// A Fastian develop a solution to this problem. He suggested to use Binary Search for inserting every 
// ith element of the array to the left part of the sorted array. He called it BinaryInsertionSort. 
// You are required to write the code of BinaryInsertionSort.

// Code 
void BinaryInsertionSort(int* arr, int n)
{
	int i, j, k, temp;
	for (i = 1; i < n; i++)
	{
			temp = arr[i];
		j = 0;
		k = i - 1;
		while (j <= k)
		{
			int m = (j + k) / 2;
			if (temp < arr[m])
				k = m - 1;
			else
				j = m + 1;
		}
		for (int l = i - 1; l >= j; l--)
			arr[l + 1] = arr[l];
		arr[j] = temp;
	}
}

// Driver code

int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	BinaryInsertionSort(arr, n);

	cout << "Sorted array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}