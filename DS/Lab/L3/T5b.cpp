#include <iostream>

using namespace std;

// Source Coordinates are (0,3)
// Destination Coordinates are (3,2)

// 0: wall
// 1: path
// 2: rat

int maze[4][4] = {
	{0, 0, 0, 1},
	{0, 1, 1, 1},
	{0, 1, 1, 0},
	{0, 0, 1, 0}
};

bool solve(int x, int y) {
	if (x == 3 && y == 3) {
		maze[x][y] = 2;
	}            
		return false;
	}                3                 3
	if (maze[x][y] != 1) {
		return false;
	}
	maze[x][y] = 2;
	if (solve(x + 1, y)) {
		return true;
	}
	if (solve(x - 1, y)) {
		return true;
	}
	if (solve(x, y + 1)) {
		return true;
	}
	if (solve(x, y - 1)) {
		return true;
	}
}

int main() {
	
	int t;
	cin >> t;
}
	           