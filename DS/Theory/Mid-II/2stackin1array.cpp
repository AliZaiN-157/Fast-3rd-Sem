#include <iostream>

using namespace std;

// Your task is to implement  2 stacks in one array efficiently.

class twoStacks
{
	int* arr;
	int size;
	int top1, top2;
public:
	twoStacks(int n) // constructor
	{
		size = n;
		arr = new int[n];
		top1 = -1;
		top2 = size;
	}

	// Method to push an element x to stack1
	void push1(int x)
	{
		// There is at least one empty space for new element
		if (top1 < top2 - 1)
		{
			top1++;
			arr[top1] = x;
		}
		else
		{
			cout << "Stack Overflow";
			return;
		}
	}

	// Method to push an element x to stack2
	void push2(int x)
	{
		// There is at least one empty space for new element
		if (top1 < top2 - 1)
		{
			top2--;
			arr[top2] = x;
		}
		else
		{
			cout << "Stack Overflow";
			return;
		}
	}

	// Method to pop an element from first stack
	int pop1()
	{
		if (top1 >= 0)
		{
			int x = arr[top1];
			top1--;
			return x;
		}
		else
		{
			return -1;
		}
	}

	// Method to pop an element from second stack
	int pop2()
	{
		if (top2 < size)
		{
			int x = arr[top2];
			top2++;
			return x;
		}
		else
		{
			return -1;
		}
	}
};

// Driver program to test twStacks class
int main()
{
	twoStacks ts(5);
	ts.push1(2);
	ts.push1(3);
	ts.push2(4);
	cout << ts.pop1() << endl;
	cout << ts.pop2() << endl;
	cout << ts.pop2() << endl;
	return 0;
}