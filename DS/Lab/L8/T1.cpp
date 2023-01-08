#include <iostream>

using namespace std;

// Create a stack in an array

class Stack {
private:
	int top;
	int size;
	int* S;
	
public:
	Stack(int size);
	~Stack();
	bool push(int x);
	int pop();
	void peek();
	bool isEmpty();
	void Display();
};

Stack::Stack(int size) {
	top = -1;
	this->size = size;
	S = new int[size];
}

Stack::~Stack() {
	delete[] S;
}

bool Stack::push(int x) {
	if (top == size - 1) {
		cout << "Stack Overflow" << endl;
		return false;
	}
	else {
		top++;
		S[top] = x;
		cout << x << " pushed into stack\n";
		return true;
	}
}

int Stack::pop() {
	int x = -1;
	if (top == -1) {
		cout << "Stack Underflow" << endl;
	}
	else {
		x = S[top--];
	}
	return x;
}

void Stack::peek() {
	if (top == -1) {
		cout << "Stack is empty" << endl;
	}
	else {
		cout << S[top] << " is at the top of the stack" << endl;
	}
}

bool Stack::isEmpty() {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

void Stack::Display() {
	for (int i = top; i >= 0; i--) {
		cout << S[i] << " ";
	}
	cout << endl;
}

int main() {
	Stack stk(10);
	if (stk.isEmpty()) 
		cout << "Stack is empty" << endl;
	else
		cout << "Stack is not empty" << endl;
	
	for (int i = 1; i <= 10; i++) {
		stk.push(i);
	}
	stk.pop();
	stk.Display();
	stk.peek();
}
