#include <iostream>

using namespace std;

// Write a function that reverses prints a linked list.
// Write a function that reverses a linked list.

class Node {
public:
	int data;
	Node* next;
	
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList {
public:
	Node* head;

	LinkedList() {
		head = NULL;
	}

	void insert(int data) {
		Node* temp = new Node(data);
		if (head == NULL) {
			head = temp;
		}
		else {
			Node* temp2 = head;
			while (temp2->next != NULL) {
				temp2 = temp2->next;
			}
			temp2->next = temp;
		}
	}

	void print() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void reversePrint(Node* head) {
		if (head == NULL) {
			return;
		}
		reversePrint(head->next);
		cout << head->data << " ";
	}

	void reverse() {
		Node* prev = NULL;
		Node* current = head;
		Node* next = NULL;
		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
};

int main() {
	LinkedList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);
	list.insert(7);
	list.insert(8);
	list.insert(9);
	list.insert(10);
	list.print();
	list.reversePrint(list.head);
	cout << endl;
	list.reverse();
	list.print();
	return 0;
}
