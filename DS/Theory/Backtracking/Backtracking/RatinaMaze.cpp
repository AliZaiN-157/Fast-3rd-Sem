#include <iostream>

using namespace std;

int n = 4;

bool isSafe(int maze[n][n], int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool solveMaze(int maze[n][n], int x, int y, int sol[n][n]) {
	if (x == n - 1 && y == n - 1 && maze[x][y] == 1) {
		return true;
	}


}

bool checkMaze(int maze[n][n]) {

	int sol[n][n] = {
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};

	if (solveMaze(maze, 0, 0, sol) == false) {
		cout << "No Solution";
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
	}
}

int main() {

	int maze[n][n] = {
		{1,0,0,0},
		{1,0,0,0},
		{1,1,0,0},
		{1,1,1,1}
	};

	solveMaze(maze);
}