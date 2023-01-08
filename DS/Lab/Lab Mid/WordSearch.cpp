#include <iostream>
#include <string>

using namespace std;

// Word Search using Backtracking

// Global Variables
char word[10];
char grid[10][10];
int n;
int count = 0;

// Function to check if the word is present in the grid
bool isPresent(int i, int j, int k)
{
	if (i < 0 || j < 0 || i >= n || j >= n)
		return false;
	if (grid[i][j] != word[k])
		return false;
	if (k == strlen(word) - 1)
		return true;
	return isPresent(i + 1, j, k + 1) || isPresent(i - 1, j, k + 1) || isPresent(i, j + 1, k + 1) || isPresent(i, j - 1, k + 1);
}

// Function to find the word in the grid
void findWord()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isPresent(i, j, 0))
			{
				cout << "Word found at (" << i << ", " << j << ")" << endl;
				count++;
			}
		}
	}
}

// Driver Code
int main()
{
	cout << "Enter the size of the grid: ";
	cin >> n;
	cout << "Enter the grid: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}
	cout << "Enter the word to be searched: ";
	cin >> word;
	findWord();
	if (count == 0)
		cout << "Word not found" << endl;
	return 0;
}

//Output
//
//Enter the size of the grid : 3
//Enter the grid :
//A B C E
//S F C S
//A D E E
//Enter the word to be searched : ABCCED