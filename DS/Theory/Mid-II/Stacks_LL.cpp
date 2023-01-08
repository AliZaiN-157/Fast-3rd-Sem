#include <iostream>

using namespace std;

// Stacks with Linked List.

class Node {
public:
	int data;
	Node* next;
	
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

class Stack {
	Node* head;
	int size;
	
public:
	Stack() {
		head = NULL;
		size = 0;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void push(int element) {
		Node* newNode = new Node(element);
		newNode->next = head;
		head = newNode;
		size++;
	}

	int pop() {
		if (isEmpty()) {
			cout << "Stack is Empty" << endl;
			return 0;
		}
		int temp = head->data;
		Node* a = head;
		head = head->next;
		delete a;
		size--;
		return temp;
	}

	int top() {
		if (isEmpty()) {
			cout << "Stack is Empty" << endl;
			return 0;
		}
		return head->data;
	}
};

int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	s.push(70);
	s.push(80);
	s.push(90);
	s.push(100);

	cout << s.top() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	return 0;
}
