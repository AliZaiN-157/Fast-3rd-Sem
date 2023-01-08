#include <iostream>

using namespace std;

int n = 4;
int maze[4][4] = {
	{1, 0, 0, 0},
	{1, 1, 0, 0},
	{0, 1, 0, 0},
	{1, 1, 1, 1}
};


bool CheckSafe(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1) { 
		return true;
	}
	return false;
}

bool solve(int x, int y, int optpath[4][4]) {
	if (x == n - 1 && y == n - 1) {
		optpath[x][y] = 1;
		return true;
		cout << "move to (" << x  << "," << y << ")" << endl;
	}
	if (CheckSafe(x, y)) {
		optpath[x][y] = 1;
		if (solve(x + 1, y, optpath)) {
			return true;
			cout << "move to (" << x+1  << "," << y << ")" << endl;
		}
		if (solve(x, y + 1, optpath)) {
			return true;
			cout << "move to (" << x << "," << y+1 << ")" << endl;

		}
		optpath[x][y] = 0;
		return false;
	}
	return false;
}

int main() {
	int optpath[4][4] = { 0 };
	if (solve(0, 0, optpath)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << optpath[i][j] << " ";
			}
			cout << endl;
		}
	}
}