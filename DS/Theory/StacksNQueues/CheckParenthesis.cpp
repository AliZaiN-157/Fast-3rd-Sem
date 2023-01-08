#include <iostream>

using namespace std;

// Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.

class Stack
{
private:
	int top;
	int size;
	char* S;
public:
	Stack(int size);
	~Stack();
	void push(char x);
	char pop();
	char peek(int index);
	int stackTop();
	int isEmpty();
	int isFull();
};

Stack::Stack(int size)
{
	this->size = size;
	top = -1;
	S = new char[size];
}

Stack::~Stack()
{
	delete[]S;
}

void Stack::push(char x)
{
	if (isFull())
		cout << "Stack Overflow" << endl;
	else
	{
		top++;
		S[top] = x;
	}
}

char Stack::pop()
{
	char x = -1;
	if (isEmpty())
		cout << "Stack Underflow" << endl;
	else
	{
		x = S[top];
		top--;
	}
	return x;
}

char Stack::peek(int index)
{
	char x = -1;
	if (top - index + 1 < 0)
		cout << "Invalid Index" << endl;
	else
		x = S[top - index + 1];
	return x;
}

int Stack::stackTop()
{
	if (isEmpty())
		return -1;
	return top;
}

int Stack::isEmpty()
{
	if (top == -1)
		return 1;
	return 0;
}

int Stack::isFull()
{
	return top == size - 1;
}

int isBalanced(char* exp)
{
	Stack stk(strlen(exp));
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
			stk.push(exp[i]);
		else if (exp[i] == ')')
		{
			if (stk.isEmpty())
				return 0;
			stk.pop();
		}
	}
	return stk.isEmpty() ? 1 : 0;
}
