#include <iostream>

using namespace std;

// Create Doubly Linked List.

// Create Node.
class Node {
public:
	int data;
	Node* next;
	Node* prev;
	
	Node(int data) {
		this->data = data;
		next = NULL;
		prev = NULL;
	}
};

// Create Linked List

class LinkedList {
public:
	Node* head;
	LinkedList() {
		head = NULL;
	}
	
	// Insert Node at the beginning of the list.
	void insertAtBeginning(int data) {
		Node* newNode = new Node(data);
		newNode->next = head;
		newNode->prev = NULL;
		if (head != NULL) {
			head->prev = newNode;
		}
		head = newNode;
	}
	
	// Insert Node at the end of the list.
	void insertAtEnd(int data) {
		Node* newNode = new Node(data);
		newNode->next = NULL;
		Node* temp = head;
		if (head == NULL) {
			newNode->prev = NULL;
			head = newNode;
			return;
		}
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
	
	// print list.
	void printList() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	
	// reverse list.
	void reverseList() {
		Node* temp = NULL;
		Node* current = head;
		while (current != NULL) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		if (temp != NULL) {
			head = temp->prev;
		}
	}

	//sort List.
	void sortList() {
		Node* current = head;
		Node* index = NULL;
		int temp;
		if (head == NULL) {
			return;
		}
		else {
			while (current != NULL) {
				index = current->next;
				while (index != NULL) {
					if (current->data > index->data) {
						temp = current->data;
						current->data = index->data;
						index->data = temp;
					}
					index = index->next;
				}
				current = current->next;
			}
		}
	}

};

int main() {
	LinkedList* list = new LinkedList();
	list->insertAtBeginning(1);
	list->insertAtBeginning(2);
	list->insertAtBeginning(3);
	list->insertAtBeginning(4);
	list->insertAtBeginning(5);
	list->insertAtBeginning(6);
	list->insertAtBeginning(7);
	list->insertAtBeginning(8);
	list->insertAtBeginning(9);
	list->insertAtBeginning(10);
	list->insertAtEnd(11);
	list->insertAtEnd(12);
	list->insertAtEnd(13);
	list->insertAtEnd(14);
	list->insertAtEnd(15);
	list->insertAtEnd(16);
	list->insertAtEnd(17);
	list->insertAtEnd(18);
	list->insertAtEnd(19);
	list->insertAtEnd(20);
	list->printList();
	list->reverseList();
	list->printList();
	list->sortList();
	list->printList();
	return 0;
}

