#include <iostream>

using namespace std;

// Find the number of unique paths the robot can take in a given maze to reach a given destination from a given source.
// The robot can move in any direction (up, down, left, right) and cannot move through walls.

// The maze is represented as a 2D array of 0s and 1s, where 0 represents a wall and 1 represents a path.
// The source and destination are represented as a pair of coordinates (x, y).

// The robot can only move in the four cardinal directions (up, down, left, right).
// The robot cannot move through walls.
// The robot cannot move outside the maze.
// The robot cannot move to a cell that it has already visited.

// The robot can move to any adjacent cell that is not a wall.

int maze[4][4] = {
		{0, 0, 1, 1},
		{0, 0, 1, 1},
		{0, 0, 1, 0},
		{0, 0, 1, 0}

};

int visited[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
};

int count = 0;

void findPaths(int x, int y, int destX, int destY) {
	if (x == destX && y == destY) {
		count++;
		return;
	}

	if (x < 0 || x >= 4 || y < 0 || y >= 4) {
		return;
	}

	if (maze[x][y] == 0) {
		return;
	}

	if (visited[x][y] == 1) {
		return;
	}

	visited[x][y] = 1;

	findPaths(x + 1, y, destX, destY); // down
	findPaths(x - 1, y, destX, destY); // up
	findPaths(x, y + 1, destX, destY); // right
	findPaths(x, y - 1, destX, destY); // left

	visited[x][y] = 0; // multiple paths dhundh sake
}

int main() {
	findPaths(0, 3, 3, 2);
	cout << count << endl;
}