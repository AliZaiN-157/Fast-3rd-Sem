#include <iostream>

using namespace std;

// Sudoku Solver

// 1. Find an empty cell
// 2. Try all numbers from 1 to 9
// 3. Check if that number is valid in the empty cell
// 4. Repeat until the grid is full


// Check if a given number is valid in a given row
bool isValidInRow(int grid[][9], int row, int num) {
	for (int col = 0; col < 9; col++) {
		if (grid[row][col] == num) {
			return false;
		}
	}
	return true;
}

// Check if a given number is valid in a given column
bool isValidInCol(int grid[][9], int col, int num) {
	for (int row = 0; row < 9; row++) {
		if (grid[row][col] == num) {
			return false;
		}
	}
	return true;
}

// Check if a given number is valid in a 3x3 box
bool isValidInBox(int grid[][9], int boxStartRow, int boxStartCol, int num) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (grid[row + boxStartRow][col + boxStartCol] == num) {
				return false;
			}
		}
	}
	return true;
}

// Check if a given number is valid in a given cell
bool isValid(int grid[][9], int row, int col, int num) {
	return isValidInRow(grid, row, num) && isValidInCol(grid, col, num) && isValidInBox(grid, row - row % 3, col - col % 3, num);
}

// Find an empty cell and update the row and column parameters
bool findEmptyCell(int grid[][9], int& row, int& col) {
	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			if (grid[row][col] == 0) {
				return true;
			}
		}
	}
	return false;
}

// Solve the Sudoku
bool solveSudoku(int grid[][9]) {
	int row, col;

	// If there is no empty cell, we are done
	if (!findEmptyCell(grid, row, col)) {
		return true;
	}

	// Consider digits 1 to 9
	for (int num = 1; num <= 9; num++) {

		// If looks promising
		if (isValid(grid, row, col, num)) {

			// Make tentative assignment
			grid[row][col] = num;

			// Return, if success, yay!
			if (solveSudoku(grid)) {
				return true;
			}

			// Failure, unmake & try again
			grid[row][col] = 0;
		}
	}

	// This triggers backtracking
	return false;
}

// Print the grid
void printGrid(int grid[][9]) {
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}
}

int main() {
	int grid[9][9] = {
		{ 3, 0, 6, 5, 0, 8, 4, 0, 0 },
		{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
		{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
		{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
		{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
		{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
		{ 0, 0, 5, 2, 0, 6, 3, 0, 0 }
	};

	if (solveSudoku(grid) == true) {
		printGrid(grid);
	}
	else {
		cout << "No solution exists";
	}

	return 0;
}