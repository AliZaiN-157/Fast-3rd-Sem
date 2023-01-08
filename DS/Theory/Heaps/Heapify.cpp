#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}

void HeapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}

void deleteRoot(int arr[], int& n)
{
	swap(arr[0], arr[n - 1]);
	n--;
	Heapify(arr, n, 0);
}

void PrintArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << " ";
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	//HeapSort(arr, n);
	
	Heapify(arr,n,0);

	cout << "Sorted array is " << endl;
	PrintArray(arr, n);
}
