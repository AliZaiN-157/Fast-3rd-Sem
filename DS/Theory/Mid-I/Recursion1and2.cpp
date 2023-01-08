#include <iostream>

using namespace std;

// Write a tail recursive function that computes the average of a list of integers.

int average(int list[], int size, int sum, int count) {
	if (size == 0) {
		return sum / count;
	}
	return average(list, size - 1, sum + list[size - 1], count + 1);
}

// Write a tail recursive function that returns the smallest element of a list of integers.

int smallest(int list[], int size, int min) {
	if (size == 0) {
		return min;
	}
	if (list[size - 1] < min) {
		min = list[size - 1];
	}
	return smallest(list, size - 1, min);
}

int main() {
	int list[] = { 1, 2, 3, 4, 5 };
	cout << average(list, 5, 0, 0) << endl;
	
	int list2[] = { 5, 4, 3, 2, 1 };
	cout << smallest(list2, 5, list2[0]) << endl;
	
	return 0;
}