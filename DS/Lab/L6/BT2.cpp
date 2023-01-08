#include <iostream>

using namespace std;

// Doubly Linked List

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

class DoublyLinkedList {
public:
	Node* head;

	DoublyLinkedList() {
		this->head = NULL;
	}

	void insert(int data) {
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
			newNode->prev = temp;
		}
	}

	void display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			cout << temp->next << " ";	
			temp = temp->next;
		}
		cout << endl;
	}
	
	// swap Nodes.
	void swapNodes(int x, int y) {
		// Nothing to do if x and y are same
		if (x == y) return;

		// Search for x (keep track of prevX and CurrX)
		Node* prevX = NULL, * currX = head;
		while (currX && currX->data != x) {
			prevX = currX;
			currX = currX->next;
		}

		// Search for y (keep track of prevY and CurrY)
		Node* prevY = NULL, * currY = head;
		while (currY && currY->data != y) {
			prevY = currY;
			currY = currY->next;
		}

		// If either x or y is not present, nothing to do
		if (currX == NULL || currY == NULL)
			return;

		// If x is not head of linked list
		if (prevX != NULL)
			prevX->next = currY;
		else // Else make y as new head
			head = currY;

		// If y is not head of linked list
		if (prevY != NULL)
			prevY->next = currX;
		else // Else make x as new head
			head = currX;

		// Swap next pointers
		Node* temp = currY->next;
		currY->next = currX->next;
		currX->next = temp;

		// Swap prev pointers
		temp = currY->prev;
		currY->prev = currX->prev;
		currX->prev = temp;
	}
	
	// sort and swap Nodes.
	void sort() {
		Node* temp = head;
		while (temp != NULL) {
			Node* temp2 = temp->next;
			while (temp2 != NULL) {
				if (temp->data > temp2->data) {
					swapNodes(temp->data, temp2->data);
				}
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
	}
};

int main() {
	DoublyLinkedList* list = new DoublyLinkedList();
	list->insert(14);
	list->insert(5);
	list->insert(39);
	list->insert(21);
	list->insert(1);
	list->display();
	list->sort();
	list->display();
	return 0;
}