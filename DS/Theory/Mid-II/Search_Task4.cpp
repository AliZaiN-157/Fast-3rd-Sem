#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Courses = {PF, OOP, DSA, DBMS, DAA, SE, Web, APP, AI, ML, NN}
// Perform a binary search on the array Courses and return the indices of every course searched for

void binarySearch(string arr[], int l, int r, string x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			cout << "Course found at index " << mid << endl;
		if (arr[mid] > x)
			binarySearch(arr, l, mid - 1, x);
		if (arr[mid] < x)
			binarySearch(arr, mid + 1, r, x);
	}
}

int main()
{
	string Courses[] = { "PF", "OOP", "DSA", "DBMS", "DAA", "SE", "Web", "APP", "AI", "ML", "NN" };
	
	// sort the string array.
	
	sort(Courses, Courses + 11);
	int n = sizeof(Courses) / sizeof(Courses[0]);
	string search;
	cout << "Enter the course you want to search: ";
	cin >> search;

	binarySearch(Courses, 0, n - 1, search);
	/*int start = 0;
	int end = n - 1;
	int mid = (start + end) / 2;
	while (start <= end)
	{
		if (Courses[mid] == search)
		{
			cout << "Course found at index " << mid << endl;
			break;
		}
		else if (Courses[mid] < search)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
		mid = (start + end) / 2;
	}
	if (start > end)
	{
		cout << "Course not found" << endl;
	}*/
	return 0;
}