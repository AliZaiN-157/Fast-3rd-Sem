#include <iostream>

using namespace std;

void MinMax(int *arr, int size)
{
	int *largest = arr;
	int *smallest = arr;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > *largest)
		{
			largest = arr + i;
		}
		if (arr[i] < *smallest)
		{
			smallest = arr + i;
		}
	}
	cout << "The largest element is " << *largest << endl;
	cout << "The smallest element is " << *smallest << endl;
}

int main()
{
	int arr[] = { 22, 2, 3, 4, 5, 6, 7, 8, 9, -10 };
	MinMax(arr, 10);
	return 0;
}



