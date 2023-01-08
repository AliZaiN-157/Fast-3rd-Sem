#include <iostream>

using namespace std;

// Stack in Linked list

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
public:
	Node* head;
	int size;
	
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

	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty" << endl;
			return;
		}
		int data = head->data;
		Node* temp = head;
		head = head->next;
		cout << data << " is popped" << endl;
		delete temp;
		size--;
	}

	int top() {
		if (isEmpty()) {
			cout << "Stack is empty" << endl;
			return 0;
		}
		return head->data;
	}

	// forward traversing
	void print() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	// reverse traversing
	void printReverse(Node* head) {
		if (head == NULL) {
			return;
		}
		printReverse(head->next);
		cout << head->data << " ";
	}
};

int main() {
	Stack stk;

	stk.push(2);
	stk.push(3);
	stk.push(4);
	stk.push(5);
	stk.push(6);
	stk.push(7);

	stk.print();
	stk.printReverse(stk.head);

	cout << endl;
	cout << "Top: " << stk.top() << endl;
	stk.pop();

}
