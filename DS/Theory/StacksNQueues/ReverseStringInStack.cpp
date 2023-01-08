#include <iostream>

using namespace std;

// You are given a string S, the task is to reverse the string using stack.

class Stack {
private:
	int top;
	int size;
	char* S;
public:
	Stack(int size);
	~Stack();
	void push(char x);
	char pop();
	int isEmpty();
	int isFull();
	char stackTop();
};

Stack::Stack(int size) {
	this->size = size;
	top = -1;
	S = new char[size];
}

Stack::~Stack() {
	delete[]S;
}

void Stack::push(char x) {
	if (isFull())
		cout << "Stack Overflow" << endl;
	else {
		top++;
		S[top] = x;
	}
}

char Stack::pop() {
	char x = -1;
	if (isEmpty())
		cout << "Stack Underflow" << endl;
	else {
		x = S[top];
		top--;
	}
	return x;
}

int Stack::isEmpty() {
	if (top == -1)
		return 1;
	return 0;
}

int Stack::isFull() {
	if (top == size - 1)
		return 1;
	return 0;
}

char Stack::stackTop() {
	if (isEmpty())
		return -1;
	return S[top];
}

void Reverse(char* str, int n) {
	Stack stk(n);
	for (int i = 0; i < n; i++)
		stk.push(str[i]);
	for (int i = 0; i < n; i++)
		str[i] = stk.pop();
}

int main() {
	char str[] = "AliZain";
	Reverse(str, strlen(str));
	cout << "Reversed string is " << str << endl;
	return 0;
}