#include<iostream>

using namespace std;

// advance paranthesis matching using stacks

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
	int isEmpty()
	{
		if (top == -1)
			return 1;
		return 0;
	}
	int isFull()
	{
		if (top == size - 1)
			return 1;
		return 0;
	}
	void Display()
	{
		for (int i = top; i >= 0; i--)
			cout << S[i] << " ";
		cout << endl;
	}

	
};



int isBalanced(string exp)
{
	Stack stk(exp.length());
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			stk.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (stk.isEmpty())
				return 0;
			char x = stk.pop();
			if (exp[i] == ')' && x != '(')
				return 0;
			else if (exp[i] == '}' && x != '{')
				return 0;
			else if (exp[i] == ']' && x != '[')
				return 0;
		}
	}
	return stk.isEmpty() ? 1 : 0;
}

// Count the number of paranthesis in the expression

int countParanthesis(string exp)
{
	Stack stk(exp.length());
	int count = 0;
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			stk.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (stk.isEmpty())
				return 0;
			char x = stk.pop();
			if (exp[i] == ')' && x != '(')
				return 0;
			else if (exp[i] == '}' && x != '{')
				return 0;
			else if (exp[i] == ']' && x != '[')
				return 0;
			else
				count++;
		}
	}
	return count;
}

int main()
{
	string exp = "{(a+b)*(c-d)}";
	cout << isBalanced(exp) << endl;
	cout << countParanthesis(exp) << endl;
	return 0;
}