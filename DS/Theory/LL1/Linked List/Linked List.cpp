#include <iostream>

using namespace std;

// Create Linked List Example.

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
		this->next = next;
	}
};

class LinkedList {

	Node* head;

public:

	LinkedList() {
		head = NULL; // Creating an Empty Linked List
	}

	void insert(int data) {
		Node* newNode = new Node(data); // Inserting New Node
		Node* temp; // 
		
		// Check Linked List is empty
		if (head == NULL) {
			head = newNode;
		}
		// If Linked List is not empty.
		else {
			temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	
	// Write a function that inserts a node in the linked list at the head of the linked list.
	void insertAtHead(int data) {
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
	}
	/*void insertAtHead(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
		}
		else {
			while (head->next != NULL) {
				head = head->next;
			}
			head->next = newNode;
		}
	}*/
	
	// Display Linked List
	void Print() {
		Node* temp = head; // head pointer is store in temp Node

		// Check Linked List is empty
		if (head == NULL) {
			cout << "Linked List is Empty" << endl;
		}
		else {
			while (temp != NULL) {
				cout << temp->data << " ";
				//cout << temp->next << " "; address of next node
				temp = temp->next;
			}
			cout << endl;
		}
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
	LinkedList obj;
	obj.insert(2);
	obj.insert(3);
	obj.insert(4);
	obj.insert(5);
	obj.insert(6);
	obj.Print();
	cout << endl;
	obj.reverse();
	obj.Print();
	cout << endl;
	LinkedList list;
	list.insertAtHead(1);
	list.insertAtHead(2);
	list.insertAtHead(3);
	list.insertAtHead(4);
	list.Print();
	cout << endl;
	list.reverse();
	list.Print();
}
