#include <iostream>

using namespace std;

// Print Reverse Singly Linked List using recursion.


// Node class
class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	Node(){
		this->data = 0;
		this->next = NULL;
	}
};

// LinkedList class

class LinkedList {
public:
	Node* head;
	Node* tail;
	
	LinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}

	// Add node to the end of the list
	
	void addNode(int data) {
		Node* newNode = new Node(data);
		if (this->head == NULL) {
			this->head = newNode;
			this->tail = newNode;
		}
		else {
			this->tail->next = newNode;
			this->tail = newNode;
		}
	}
	
	// Print the list
	
	void printList() {
		Node* temp = this->head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	
	// Print the list in reverse order
	
	void printReverseList(Node* head) {
		if (head == NULL) {
			return;
		}
		printReverseList(head->next);
		cout << head->data << " ";
	}

	void Display(Node* head) {
		if (head == NULL) {
			return;
		}
		cout << head->data << " ";
		Display(head->next);
	}
};

int main() {
	LinkedList* list = new LinkedList();
	list->addNode(1);
	list->addNode(2);
	list->addNode(3);
	list->addNode(4);
	list->addNode(5);
	list->printList();
	list->printReverseList(list->head);
	cout << endl;
	list->Display(list->head);
	return 0;
}