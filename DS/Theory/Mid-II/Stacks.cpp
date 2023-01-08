#include <iostream>

using namespace std;

// Stacks are a type of data structure that are used to store data in a LIFO (Last In First Out) manner.

class Stack {
private:
	int top;
	int size;
	int* S;
public:
	Stack(int size){
		this->size = size;
		top = -1;
		S = new int[size];
	}
	~Stack() {
		delete[]S;
	}
	
	void push(int x)
	{
		if (top == size - 1)
			cout << "Stack Overflow" << endl;
		else
		{
			top++;
			S[top] = x;
		}
	}
	int pop()
	{
		int x = -1;
		if (top == -1)
			cout << "Stack Underflow" << endl;
		else
		{
			x = S[top];
			top--;
		}
		return x;
	}
	int peek(int index)
	{
		int x = -1;
		if (top - index + 1 < 0)
			cout << "Invalid Index" << endl;
		else
			x = S[top - index + 1];
		return x;
	}
	int stackTop()
	{
		if (top == -1)
			return -1;
		return S[top];
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
	
	void display()
	{
		for (int i = top; i >= 0; i--)
			cout << S[i] << " ";
		cout << endl;
	}
	
	
	
};

int main()
{
	Stack stk(5);
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);
	stk.push(50);
	stk.display();
	cout << stk.pop() << endl;
	stk.display();
	cout << stk.peek(3) << endl;
	cout << stk.stackTop() << endl;
	cout << stk.isEmpty() << endl;
	stk.push(100);
	cout << stk.isFull() << endl;
	return 0;
}