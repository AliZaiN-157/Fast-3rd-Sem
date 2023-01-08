#include <iostream>
using namespace std;

int main()
{
	int arr[]= { 0, 1, 15, 25, 6, 7, 30, 40, 50};
	int n = sizeof(arr) / sizeof(arr[0]);
	int i = 0, j = n - 1;
	while (i < n - 1 && arr[i] <= arr[i + 1])
	{
		i++;
	}
	if (i == n - 1)
	{
		cout << "The array is already sorted";
		return 0;
	}
	while (j > 0 && arr[j] >= arr[j - 1])
	{
		j--;
	}
	int min = arr[i];
	int max = arr[i];
	for (int k = i + 1; k <= j; k++)
	{
		if (arr[k] < min)
		{
			min = arr[k];
		}
		if (arr[k] > max)
		{
			max = arr[k];
		}
	}
	while (i > 0 && arr[i - 1] > min)
	{
		i--;
	}
	while (j < n - 1 && arr[j + 1] < max)
	{
		j++;
	}
	cout << "The unsorted subarray sorted lies between the indices " << i << " and " << j;
	
	
	return 0;
}



