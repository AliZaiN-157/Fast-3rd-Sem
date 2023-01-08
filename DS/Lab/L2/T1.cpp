#include <iostream>
using namespace std;

int main()
{
	int m;
	cout << "Enter the number of rows and columns of the matrix: ";
	cin >> m;
	int a[m][m];
	cout << "Enter the elements of the matrix: ";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == j && a[i][j] != 1)
			{
				flag = 1;
			}
			if (i != j && a[i][j] != 0)
			{
				flag = 1;
			}
		}
	}
	if (flag == 0)
	{
		cout << "The matrix is an Identity matrix";
	}
	else
	{
		cout << "The matrix is not an Identity matrix";
	}
	return 0;
}