#include <iostream>
using namespace std;

// N queens program.

// Global variables.
int N=4;
int board[4][4] = { 0 };

// Function prototypes.
void printBoard();
bool isSafe(int row, int col);
bool solveNQueens(int col);

int main()
{
	if (solveNQueens(0) == false)
	{
		cout << "No Solution" << endl;
		return false;
	}

	printBoard();
	return 0;
}

void printBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

bool isSafe(int row, int col)
{
	int i, j;

	// Check this row on left side.
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	// Check upper diagonal on left side.
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	// Check lower diagonal on left side.
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}


bool solveNQueens(int col)
{
	// If all queens are placed then return true.
	if (col >= N)
		return true;

	// Consider this column and try placing this queen in all rows one by one.
	for (int i = 0; i < N; i++)
	{
		// Check if the queen can be placed on board[i][col].
		if (isSafe(i, col))
		{
			// Place this queen in board[i][col].
			board[i][col] = 1;

			// Recur to place rest of the queens.
			if (solveNQueens(col + 1))
				return true;

			// If placing queen in board[i][col] doesn't lead to a solution then remove queen from board[i][col].
			board[i][col] = 0; // BACKTRACK.
		}
	}

	// If queen can not be place in any row in this column then return false.
	return false;
}


// Resources: Online resources, docs and articles.



