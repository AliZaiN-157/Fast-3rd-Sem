#include <iostream>
using namespace std;

// Infix to Postfix using stack 

class Stack
{
private:
	int top;
	int size;
	char* S;

public:
	Stack(int size)
	{
		this->size = size;
		top = -1;
		S = new char[size];
	}
	~Stack()
	{
		delete[]S;
	}
	void push(char x)
	{
		if (top == size - 1)
			cout << "Stack Overflow" << endl;
		else
		{
			top++;
			S[top] = x;
		}
	}
	char pop()
	{
		char x = -1;
		if (top == -1)
			cout << "Stack Underflow" << endl;
		else
		{
			x = S[top];
			top--;
		}
		return x;
	}
	char peek(int index)
	{
		char x = -1;
		if (top - index + 1 < 0)
			cout << "Invalid Index" << endl;
		else
			x = S[top - index + 1];
		return x;
	}
	int isEmpty()
	{
		if (top == -1)
			return 1;
		return 0;
	}
	int isFull()
	{
		return top == size - 1;
	}
	char stackTop()
	{
		if (!isEmpty())
			return S[top];
		return -1;
	}
};

int inPre(char x)
{
	if (x == '^')
		return 3;
	else if (x == '*' || x == '/')
		return 2;
	else if (x == '+' || x == '-')
		return 1;
	return 0;
}

void InfixToPostfix(string infix)
{
	Stack stk(infix.length());
	string postfix;
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
			postfix += infix[i];
		else if (infix[i] == '(')
			stk.push(infix[i]);
		else if (infix[i] == ')')
		{
			for (int j = stk.stackTop(); j != '('; j = stk.stackTop())
				postfix += stk.pop();
			stk.pop();
		}
		else
		{
			for (int j = stk.stackTop(); inPre(j) >= inPre(infix[i]); j = stk.stackTop())
				postfix += stk.pop();
			stk.push(infix[i]);
		}
	}
	for (int i = stk.stackTop(); i != -1; i = stk.stackTop())
		postfix += stk.pop();
	cout << postfix << endl;
}

int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	InfixToPostfix(exp);
	return 0;
}



	