#include <iostream>

using namespace std;

// function 
bool canWin(int arr[], int n, int start, int p1, int p2, int turn) {
	if (n == 0) {
		if (p1 > p2) {
			return true;
		}
		else {
			return false;
		}
	}
	if (turn == 1) {
		if (arr[start] > arr[n-1])
			return canWin(arr, n, start++ ,p1 + arr[0], p2, 2); 
		else
			return canWin(arr, n--, start, p1 + arr[n-1], p2, 2);
	}
	else {
		if (arr[start] > arr[n-1])
			return canWin(arr, n, start++, p1, p2 + arr[0], 1); 
		else
			return canWin(arr, n--, start, p1, p2 + arr[n-1], 1);
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (canWin(arr, n, 0, 0, 0, 1)) {
		cout << "Player 1 can win the game" << endl;
	}
	else {
		cout << "Player 1 cannot win the game" << endl;
	}
	return 0;
}



