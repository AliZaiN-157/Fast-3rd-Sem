#include <iostream>

using namespace std;

int i = 0;

void sequence(int iter, int num, int diff) {
	
	int sum = 0;
	if (i != iter) {

		i++;
		sum = num;
		cout << sum << " ";
		sum += diff;
		diff++;
		sequence(iter, sum, diff);
	}
}

int main() {

	int n;
	cout << "Number of elements: ";
	cin >> n;

	// Sequence 1
	cout << "Sequence 1: ";
	sequence(n, 1, 2);

	cout << endl;
	i = 0; // setting i = 0 so that 2nd Sequence can be print.
	// Sequence 2

	cout << "Sequence 2: ";
	sequence(n, 1, 0);
}
