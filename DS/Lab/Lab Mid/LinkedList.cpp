#include <iostream>

using namespace std;

// node class
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

// linked list class
class LinkedList {
private:
	Node* head;

public:
	LinkedList() {
		head = NULL;
	}

	// insert at the end of the list
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
		}
	}

	// insert at the beginning of the list
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

	// print
	void print() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	// Delete last occurrence of an item from linked list
	void deleteLastOccurrence(int data) {
		Node* temp = head;
		Node* prev = NULL;
		Node* lastOccurrence = NULL;
		Node* lastOccurrencePrev = NULL;

		while (temp != NULL) {
			if (temp->data == data) {
				lastOccurrencePrev = prev;
				lastOccurrence = temp;
			}
			prev = temp;
			temp = temp->next;
		}

		if (lastOccurrence != NULL) {
			if (lastOccurrencePrev == NULL) {
				head = head->next;
			}
			else {
				lastOccurrencePrev->next = lastOccurrence->next;
			}
			delete lastOccurrence;
		}
	}
	
	// Merge a linked list into another linked list at alternate positions.
	void merge(LinkedList* list) {
		Node* temp1 = head;
		Node* temp2 = list->head;
		Node* temp1Next = NULL;
		Node* temp2Next = NULL;

		while (temp1 != NULL && temp2 != NULL) {
			temp1Next = temp1->next;
			temp2Next = temp2->next;

			temp2->next = temp1Next;
			temp1->next = temp2;

			temp1 = temp1Next;
			temp2 = temp2Next;
		}
	}

	// Reverse the Linked List on specified range of nodes
	void reverse(int start, int end) {
		Node* temp = head;
		Node* prev = NULL;
		Node* next = NULL;
		Node* startPrev = NULL;
		Node* endNext = NULL;
		int count = 1;

		while (temp != NULL) {
			if (count == start - 1) {
				startPrev = temp;
			}
			if (count == end + 1) {
				endNext = temp;
			}
			count++;
			temp = temp->next;
		}

		temp = head;
		count = 1;
		while (temp != NULL) {
			if (count >= start && count <= end) {
				next = temp->next;
				temp->next = prev;
				prev = temp;
				temp = next;
			}
			else {
				temp = temp->next;
			}
			count++;
		}

		if (startPrev != NULL) {
			startPrev->next = prev;
		}
		else {
			head = prev;
		}

		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = endNext;
	}
};


int main() {
	LinkedList l1;
	
	
	l1.insert(4);
	l1.insert(2);
	l1.insert(3);
	l1.insert(2);
	l1.insert(4);
	//l1.insert(2);
	l1.print();

	// Delete the last occurrence from the list
	//l1.deleteLastOccurrence(2);
	l1.reverse(2, 5);
	//l1.print();

	
	// Merge two lists
	LinkedList l2;
	
	l2.insert(1);
	l2.insert(3);
	l2.insert(5);
	l2.insert(7);
	l2.insert(9);
	l2.insert(11);
	l2.print();
	
	LinkedList l3;
	
	l3.insert(2);
	l3.insert(4);
	l3.insert(6);
	l3.insert(8);
	l3.insert(10);
	l3.print();
	
	l2.merge(&l3);
	l2.print();
}