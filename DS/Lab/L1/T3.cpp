//The problem is to get a positive integer from the keyboardand find all its factors by division method.
//After completing all factor also produce the sum of all the factors.The program should stop when a user
//entered - 1 as input.

#include <iostream>
using namespace std;


int main()
{
	int n, i, sum = 0;
	cout << "Enter a positive integer: ";
	cin >> n;
	while (n > -1) {
		for (i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				cout << i << " ";
				sum += i;
			}
		}
		cout << endl << "The sum of all the factors is: " << sum << endl;
		cin >> n;
	}
	return 0;
}