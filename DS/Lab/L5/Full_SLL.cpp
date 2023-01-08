#include <iostream>

using namespace std;

// Create Singly Linked List.

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	
	Node() {
		this->data = 0;
		this->next = NULL;
	}
};

class SLL {
public:
	Node* head;

	SLL() {
		head = NULL;
	}
	
	// Insert at Beginning.
	
	void insertAtBeginning(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	// Insert at End.
	
	void insertAtEnd(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	
	// Insert at Position.
	
	void insertAtPosition(int data, int position) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
		}
		else {
			Node* temp = head;
			for (int i = 1; i < position - 1; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	
	// Delete at Beginning.
	
	void deleteAtBeginning() {
		if (head == NULL) {
			cout << "List is Empty." << endl;
		}
		else {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	// Delete at End.
	
	void deleteAtEnd() {
		if (head == NULL) {
			cout << "List is Empty." << endl;
		}
		else {
			Node* temp = head;
			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
		}
	}
	
	// Delete at Position.
	
	void deleteAtPosition(int position) {
		if (head == NULL) {
			cout << "List is Empty." << endl;
		}
		else {
			Node* temp = head;
			for (int i = 1; i < position - 1; i++) {
				temp = temp->next;
			}
			Node* temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;
		}
	}
	
	// Display.
	
	void display() {
		if (head == NULL) {
			cout << "List is Empty." << endl;
		}
		else {
			Node* temp = head;
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	// Reverse.
	
	void reverse() {
		if (head == NULL) {
			cout << "List is Empty." << endl;
		}
		else {
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
	}

	// Search.

	bool search(int data) {
		if (head == NULL) {
			cout << "List is Empty." << endl;
			return false;
		}
		else {
			Node* temp = head;
			while (temp != NULL) {
				if (temp->data == data) {
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
	}
	
	// Search using Recursion.
	
	bool searchUsingRecursion(Node* head, int data) {
		if (head == NULL) {
			return false;
		}
		else {
			if (head->data == data) {
				return true;
			}
			else {
				return searchUsingRecursion(head->next, data);
			}
		}
	}

	// Get Size.
	
	int getSize() {
		if (head == NULL) {
			cout << "List is Empty." << endl;
			return 0;
		}
		else {
			int count = 0;
			Node* temp = head;
			while (temp != NULL) {
				count++;
				temp = temp->next;
			}
			return count;
		}
	}
	
	// Get Middle Element.
	
	int getMiddleElement() {
		if (head == NULL) {
			cout << "List is Empty." << endl;
			return 0;
		}
		else {
			Node* slow = head;
			Node* fast = head;
			while (fast != NULL && fast->next != NULL) {
				slow = slow->next;
				fast = fast->next->next;
			}
			return slow->data;
		}
	}

	// Get Nth Element.
	
	int getNthElement(int position) {
		if (head == NULL) {
			cout << "List is Empty." << endl;
			return 0;
		}
		else {
			Node* temp = head;
			for (int i = 1; i < position; i++) {
				temp = temp->next;
			}
			return temp->data;
		}
	}
	
	// Get Nth Element from End.
	
	int getNthElementFromEnd(int position) {
		if (head == NULL) {
			cout << "List is Empty." << endl;
			return 0;
		}
		else {
			Node* temp = head;
			int size = getSize();
			for (int i = 1; i < size - position + 1; i++) {
				temp = temp->next;
			}
			return temp->data;
		}
	}

	// Sort
	
	void sort() {
		if (head == NULL) {
			cout << "List is Empty." << endl;
		}
		else {
			Node* temp = head;
			while (temp != NULL) {
				Node* temp2 = temp->next;
				while (temp2 != NULL) {
					if (temp->data > temp2->data) {
						int tempData = temp->data;
						temp->data = temp2->data;
						temp2->data = tempData;
					}
					temp2 = temp2->next;
				}
				temp = temp->next;
			}
		}
	}
	
};


int main() {
	
	SLL sll;
	sll.insertAtEnd(4);
	sll.insertAtEnd(11);
	sll.insertAtEnd(2);
	sll.insertAtEnd(1);
	sll.insertAtEnd(33);
	sll.sort();
	sll.display();
	
	cout << sll.searchUsingRecursion(sll.head, 11);
	
}
	