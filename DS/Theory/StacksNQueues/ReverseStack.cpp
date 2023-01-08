#include <iostream>

using namespace std;

// How to Reverse a Stack using Recursion.

class Stack
{
private:
	int top;
	int size;
	int* S;
	
public:
	Stack(int size);
	~Stack();
	void push(int x);
	int pop();
	int peek(int index);
	int isEmpty();
	int isFull();
	int stackTop();
	void display();
	void reverse();
	void reverseUtil(int x);
	
};

Stack::Stack(int size)
{
	this->size = size;
	top = -1;
	S = new int[size];
}

Stack::~Stack()
{
	delete[] S;
}

void Stack::push(int x)
{
	if (isFull())
		cout << "Stack Overflow" << endl;
	else
	{
		top++;
		S[top] = x;
	}
}

int Stack::pop()
{
	int x = -1;
	if (isEmpty())
		cout << "Stack Underflow" << endl;
	else
	{
		x = S[top];
		top--;
	}
	return x;
}

int Stack::peek(int index)
{
	int x = -1;
	if (top - index + 1 < 0)
		cout << "Invalid Index" << endl;
	else
		x = S[top - index + 1];
	return x;
}

int Stack::isEmpty()
{
	if (top == -1)
		return 1;
	return 0;
}

int Stack::isFull()
{
	if (top == size - 1)
		return 1;
	return 0;
}

int Stack::stackTop()
{
	if (isEmpty())
		return -1;
	return S[top];
}

void Stack::display()
{
	for (int i = top; i >= 0; i--)
		cout << S[i] << " ";
	cout << endl;
}

void Stack::reverseUtil(int x)
{
	if (isEmpty())
	{
		push(x);
	}
	else
	{
		int y = pop();
		reverseUtil(x);
		push(y);
	}
}

void Stack::reverse()
{
	if (!isEmpty())
	{
		int x = pop();
		reverse();
		reverseUtil(x);
	}
}


int main()
{
	Stack stk(5);
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	stk.push(5);
	stk.display();
	stk.reverse();
	stk.display();
	return 0;
}
	