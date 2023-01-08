#include <iostream>

using namespace std;

// Write a C++ program that takes a 4x4 Matrix as input and finds what is the highest row in terms of summ for all the rows.


int main()
{
	int mat[4][4];
	int sum = 0;
	int max = 0;
	int row = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sum = sum + mat[i][j];
		}
		if (sum > max)
		{
			max = sum;
			row = i+1;
		}
		sum = 0;
	}
	cout << "The highest row is " << row << " and sum is: " <<  max  <<endl;
	return 0;
}