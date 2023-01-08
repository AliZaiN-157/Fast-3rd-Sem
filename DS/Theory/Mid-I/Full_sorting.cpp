#include <iostream>

using namespace std;

// Bubble and Insertion Sort.
void bubble_sort(int arr[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void insertion_sort(int arr[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
// Quick sort

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

// Merge Sort

// Merge
void Merge(int* A, int* L, int leftCount, int* R, int rightCount) {
	int i, j, k;

	
	i = 0; j = 0; k = 0;

	while (i < leftCount && j < rightCount) {
		if (L[i] < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	
	while (i < leftCount) 
		A[k++] = L[i++];
		
	while (j < rightCount) 
		A[k++] = R[j++];
}

// Merge Sort
void MergeSort(int* A, int n) {
	int mid, i, * L, * R;
	if (n < 2) return; 

	mid = n / 2;  

	L = new int[mid];
	R = new int[n - mid];

	for (i = 0; i < mid; i++) L[i] = A[i]; 
	for (i = mid; i < n; i++) R[i - mid] = A[i]; 

	MergeSort(L, mid);  
	MergeSort(R, n - mid);  
	Merge(A, L, mid, R, n - mid); 
	delete[] L;
	delete[] R;
}



int main() {
	
	// quick sort.
	int arr1[] = { 101, 23, 46, 96, 72, 202,81 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	quick_sort(arr1, 0, n1 - 1);
	
	for (int i = 0; i < n1; i++)
		cout << arr1[i] << " ";
	
	
	cout << endl << endl;
	
	// Merge Sort
	
	int A[] = { 33,2,101,91,5 };
	int i, numberOfElements;

	numberOfElements = sizeof(A)/ sizeof(A[0]);

	MergeSort(A, numberOfElements);

	for (i = 0; i < numberOfElements; i++)
		cout << A[i] << " ";
}