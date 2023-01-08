#include <iostream>

using namespace std;

// Circular Linked List

class Node {
public:
	int data;
	Node* next;
	
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	
};

class CLL {
private:
	Node* head;
	Node* tail;
public:
	CLL() {
		head = NULL;
		tail = NULL;
	}
	
	// insert node in the beginning.

	void insert(int data) {
		Node* temp = new Node(data);
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp->next = head;
		}
		else {
			tail->next = temp;
			tail = temp;
			tail->next = head;
		}
	}

	// insert node at the end.
	
	void insertEnd(int data) {
		Node* temp = new Node(data);
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp->next = head;
		}
		else {
			tail->next = temp;
			tail = temp;
			tail->next = head;
		}
	}
	
	void display() {
		Node* temp = head;
		while (temp->next != head) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data << " ";
	}
};


int main() {
	CLL cll;
	cll.insert(1);
	cll.insert(2);
	cll.insert(3);
	cll.insert(4);
	cll.insert(5);
	cll.insertEnd(6);
	cll.display();
	return 0;
}