#include <iostream>

using namespace std;

// Recursive Binary search.

int binary_search(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binary_search(arr, l, mid - 1, x);
		return binary_search(arr, mid + 1, r, x);
	}
	return -1;
}

// Binary Search

void binary_search2(int arr[], int begin, int end, int x)
{
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		if (arr[mid] == x) {
			cout << "Found at " << mid + 1 << endl;
			return ;
		}
			
		if (arr[mid] < x)
			begin = mid + 1;
		else
			end = mid - 1;
	}
	cout << "no element found";
}

// Interpolation Search

int interpolation_search(int arr[], int n, int x)
{
	int lo = 0, hi = (n - 1);
	while (lo <= hi && x >= arr[lo] && x <= arr[hi])
	{
		if (lo == hi)
		{
			if (arr[lo] == x) return lo;
			return -1;
		}
		int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
		if (arr[pos] == x)
			return pos;
		if (arr[pos] < x)
			lo = pos + 1;
		else
			hi = pos - 1;
	}
	return -1;
}