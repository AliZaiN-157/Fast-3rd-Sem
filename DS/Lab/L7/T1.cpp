#include <iostream>
#define MAX 20
using namespace std;

class Stack {
	int top;

public:
	int a[MAX]; // Maximum size of Stack

	Stack() 
	{ top = -1; }
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		cout << x << " pushed into stack \n";
		return true;
	}
}

int Stack::pop()
{
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}

	else {
		int x = a[top--];
		return x;
	}
}
int Stack::peek()
{
	if (top < 0) {
		cout << "Stack is Empty" << endl;
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

// Create  Main:
// 1. Insert 10 Integers values in the stack
// 2. If the Insert input reach the Highest index of Array display the message Stack overflow
// 3. Remove the Inserted values till the Last value and print the message that stack is empty



