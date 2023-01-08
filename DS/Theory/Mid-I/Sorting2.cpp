#include <iostream>

using namespace std;

// An IndirectIndexSort is a sorting algorithm that prepare an index over a collection. 
// Given an array X [] of n numbers, this sort will produced an array Y[] of indexes of sorted order 
// of these numbers. For example X[] ={13,29,91,34,56} then Y[] ={0,1,3,4,2} 
// Write an efficient implementation of this approach, you cannot move elements of array X. 
// Note that X[] may contains duplicate number and your IndirectIndexSort should be stable in nature.

// Write the Program.

int main()
{
	int X[] = { 13,29,91,34,56 };
	int Y[] = { 0,1,3,4,2 };
	int n = sizeof(X) / sizeof(X[0]);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (X[Y[i]] > X[Y[j]])
			{
				int temp = Y[i];
				Y[i] = Y[j];
				Y[j] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << Y[i] << " ";
	}
	return 0;
}