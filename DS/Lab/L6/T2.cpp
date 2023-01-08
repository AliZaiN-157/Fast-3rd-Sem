#include <iostream>

using namespace std;

// Doubly linked list.

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	
	Node(int d) {
		data = d;
		next = NULL;
		prev = NULL;
	}

	Node() {
		next = NULL;
		prev = NULL;
		data = 0;
	}
};

class List {
public:
	Node* head;

	List() {
		head = NULL;
	}
	
	// insert at the end of the list.
	void insert(int d) {
		Node* n = new Node(d);
		if (head == NULL) {
			head = n;
			return;
		}
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
		n->prev = temp;
	}

	// insert at the beginning of the list.
	void insertAtBeginning(int d) {
		Node* n = new Node(d);
		if (head == NULL) {
			head = n;
			return;
		}
		n->next = head;
		head->prev = n;
		head = n;
	}

	// insert at a given position.
	void insertAtPosition(int d, int pos) {
		Node* n = new Node(d);
		if (head == NULL) {
			head = n;
			return;
		}
		Node* temp = head;
		int count = 1;
		while (temp->next != NULL && count < pos) {
			temp = temp->next;
			count++;
		}
		if (count == pos) {
			n->next = temp->next;
			n->prev = temp;
			temp->next = n;
			if (n->next != NULL) {
				n->next->prev = n;
			}
		}
		else {
			cout << "Position not found." << endl;
		}
	}

	// delete from the end of the list.
	void deleteFromEnd() {
		if (head == NULL) {
			cout << "List is empty." << endl;
			return;
		}
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		if (temp->prev != NULL) {
			temp->prev->next = NULL;
		}
		else {
			head = NULL;
		}
		delete temp;
	}
	
	// delete from the beginning of the list.
	void deleteFromBeginning() {
		if (head == NULL) {
			cout << "List is empty." << endl;
			return;
		}
		Node* temp = head;
		head = head->next;
		if (head != NULL) {
			head->prev = NULL;
		}
		delete temp;
	}

	// delete from a given position.
	void deleteFromPosition(int pos) {
		if (head == NULL) {
			cout << "List is empty." << endl;
			return;
		}
		Node* temp = head;
		int count = 1;
		while (temp->next != NULL && count < pos) {
			temp = temp->next;
			count++;
		}
		if (count == pos) {
			if (temp->prev != NULL) {
				temp->prev->next = temp->next;
			}
			else {
				head = temp->next;
			}
			if (temp->next != NULL) {
				temp->next->prev = temp->prev;
			}
			delete temp;
		}
		else {
			cout << "Position not found." << endl;
		}
	}
	
	// print the list.
	void print() {
		if (head == NULL) {
			cout << "List is empty." << endl;
			return;
		}
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	List l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	l.insert(5);
	l.print();
	l.insertAtBeginning(0);
	l.print();
	l.insertAtPosition(6, 3);
	l.print();
	l.deleteFromEnd();
	l.print();
	l.deleteFromBeginning();
	l.print();
	l.deleteFromPosition(3);
	l.print();
	return 0;
}
