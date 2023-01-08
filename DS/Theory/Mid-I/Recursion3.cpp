#include <iostream>

using namespace std;

// Write a recursive function CountOnes that takes an unsigned integer and return the number of ones in binary representation of that given number. 
// For an example: if 28 is given as an argument to this function it will return 3, as 2810 is 111002.

int CountOnes(unsigned int n)
{
	if (n == 0)
		return 0;
	else
		return (n % 2) + CountOnes(n / 2);
}

int main()
{
	unsigned int n;
	cout << "Enter a number: ";
	cin >> n;
	cout << "Number of ones in binary representation of " << n << " is " << CountOnes(n) << endl;
	return 0;
}

