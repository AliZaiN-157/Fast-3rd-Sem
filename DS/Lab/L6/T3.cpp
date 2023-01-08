#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	
	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
	
	Node() {
		this->data = 0;
		this->next = NULL;
		this->prev = NULL;
	}
};

class List {
public:
	Node* head;

	List() {
		this->head = NULL;
	}
	
	// Insert at start.
	void insertStart(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			head->next = head;
			head->prev = head;
		}
		else {
			newNode->next = head;
			newNode->prev = head->prev;
			head->prev->next = newNode;
			head->prev = newNode;
			head = newNode;
		}
	}

	// Insert at end.
	void insertEnd(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			head->next = head;
			head->prev = head;
		}
		else {
			newNode->next = head;
			newNode->prev = head->prev;
			head->prev->next = newNode;
			head->prev = newNode;
		}
	}
	
	// Insert at position.
	void insertPos(int data, int pos) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			head->next = head;
			head->prev = head;
		}
		else {
			Node* temp = head;
			for (int i = 1; i < pos; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next->prev = newNode;
			temp->next = newNode;
		}
	}

	// Delete at start.
	void deleteStart() {
		if (head == NULL) {
			cout << "List is empty." << endl;
		}
		else {
			Node* temp = head;
			head->prev->next = head->next;
			head->next->prev = head->prev;
			head = head->next;
			delete temp;
		}
	}
	
	// Delete at end.
	void deleteEnd() {
		if (head == NULL) {
			cout << "List is empty." << endl;
		}
		else {
			Node* temp = head->prev;
			head->prev = temp->prev;
			temp->prev->next = head;
			delete temp;
		}
	}
	
	// Delete at position.
	void deletePos(int pos) {
		if (head == NULL) {
			cout << "List is empty." << endl;
		}
		else {
			Node* temp = head;
			for (int i = 1; i < pos; i++) {
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}
	
	// Display.
	void display() {
		if (head == NULL) {
			cout << "List is empty." << endl;
		}
		else {
			Node* temp = head;
			do {
				cout << temp->data << " ";
				temp = temp->next;
			} while (temp != head);
			cout << endl;
		}
	}
};

int main() {
	List list;
	list.insertEnd(1);
	list.insertEnd(2);
	list.insertEnd(3);
	list.insertEnd(4);
	list.insertEnd(5);
	list.insertEnd(6);
	list.insertStart(7);
	list.insertStart(8);
	list.insertStart(9);
	list.insertStart(10);
	list.display();
	list.deleteStart();
	list.display();
	list.deleteEnd();
	list.display();
	list.deletePos(5);
	list.display();
	list.insertPos(12, 5);
	list.display();
	return 0;
}