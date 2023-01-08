#include <iostream>
using namespace std;


int main()
{
	int n, k;
	cout << "Enter Number of Toys: ";
	cin >> n;
	cout << "Enter the Amount: ";
	cin >> k;

	int arr[3];
	cout << "Enter the cost of toys: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (k >= arr[i])
		{
			k = k - arr[i];
			count++;
		}
	}
	cout << count;
	return 0;
}