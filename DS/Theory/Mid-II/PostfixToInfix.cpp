#include <iostream>

using namespace std;

// Convert a postfix expression to the corresponding fully-parenthesizedinfix expression.
// For example, a b + and a b + c d - *should produce(a + b) and ((a + b) * (c - d)), respectively.

class Stack {
private:
	char* stack;
	int top;
	int size;
public:
	Stack(int size) {
		this->size = size;
		top = -1;
		stack = new char[size];
	}
	void push(char c) {
		if (top == size - 1) {
			cout << "Stack is full" << endl;
		}
		else {
			top++;
			stack[top] = c;
		}
	}
	char pop() {
		if (top == -1) {
			cout << "Stack is empty" << endl;
			return -1;
		}
		else {
			char c = stack[top];
			top--;
			return c;
		}
	}
	char peek() {
		if (top == -1) {
			cout << "Stack is empty" << endl;
			return -1;
		}
		else {
			return stack[top];
		}
	}
	bool isEmpty() {
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
	}
};

// postfix to infix
void postfixToInfix(char* postfix) {
	Stack s(strlen(postfix));
	int i = 0;
	while (postfix[i] != '\0') {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
			char op1 = s.pop();
			char op2 = s.pop();
			cout << "(" << op2 << postfix[i] << op1 << ")";
		}
		else {
			s.push(postfix[i]);
		}
		i++;
	}
}

int main() {
	char postfix[100];
	cout << "Enter a postfix expression: ";
	cin >> postfix;
	cout << "The corresponding infix expression is: ";
	postfixToInfix(postfix);
	cout << endl;
	return 0;
}


