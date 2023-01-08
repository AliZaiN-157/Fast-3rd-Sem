#include <iostream>

using namespace std;

int InterpolationSearch(int arr[], int n, int x)
{
	int low = 0, high = (n - 1);

	while (low <= high && x >= arr[low] && x <= arr[high])
	{
		if (low == high)
		{
			if (arr[low] == x) return low;
			return -1;
		}
		int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

		if (arr[pos] == x)
			return pos;

		if (arr[pos] < x)
			low = pos + 1;

		else
			high = pos - 1;
	}
	return -1;
}

int main()
{
	int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int x = 18;
	int index = InterpolationSearch(arr, n, x);

	if (index != -1)
		cout << "Element found at index " << index;
	else
		cout << "Element not found.";
	return 0;
}