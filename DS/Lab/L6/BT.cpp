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

	Node()
	{
		this->data = 0;
		this->next = NULL;
		this->prev = NULL;
	}
};

class LinkedList {
public:
	Node* head;
	Node* tail;
	int size;
	LinkedList() {
		this->head = NULL;
		this->tail = NULL;
		this->size = 0;
	}

	void addLast(int data) {
		Node* nn = new Node(data);
		if (this->size == 0) {
			this->head = nn;
			this->tail = nn;
		}
		else {
			this->tail->next = nn;
			nn->prev = this->tail;
			this->tail = nn;
		}
		this->size++;
	}

	void display() {
		Node* temp = this->head;
		while (temp != NULL) {
			cout << temp->data << " ";
			cout << temp->next << " ";
		
			temp = temp->next;
			cout << endl;
		}
		cout << endl;
	}
	
	// function to sort linked list using insertion sort.

	void sortedInsert(Node** head_ref, Node* new_node)
	{
		Node* current;
		/* Special case for the head end */
		if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
		{
			new_node->next = *head_ref;
			*head_ref = new_node;
		}
		else
		{
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != NULL &&
				current->next->data < new_node->data)
			{
				current = current->next;
			}
			new_node->next = current->next;
			current->next = new_node;
		}
	}
	
	void insertionSort() {
		// Initialize sorted linked list
		Node* sorted = NULL;

		// Traverse the given linked list and insert every
		// node to sorted
		Node* current = head;
		while (current != NULL)
		{
			// Store next for next iteration
			Node* next = current->next;

			// insert current in sorted linked list
			sortedInsert(&sorted, current);

			// Update current
			current = next;
		}

		// Update head_ref to point to sorted linked list
		head = sorted;
	}

	void sort() {
		// Initialize sorted linked list
		Node* sorted = NULL;

		// Traverse the given linked list and insert every
		// node to sorted
		Node* current = head;
		while (current != NULL)
		{
			// Store next for next iteration
			Node* next = current->next;

			// insert current in sorted linked list
			//sortedInsert(&sorted, current);
			
			Node* temp;
			/* Special case for the head end */
			if (sorted == NULL || (sorted)->data >= current->data)
			{
				current->next = sorted;
				sorted = current;
			}
			else
			{
				/* Locate the node before the point of insertion */
				temp = sorted;
				while (temp->next != NULL &&
					temp->next->data < current->data)
				{
					temp = temp->next;
				}
				current->next = temp->next;
				temp->next = current;
			}
			

			// Update current
			current = next;
		}

		// Update head_ref to point to sorted linked list
		head = sorted;
	}
	
	
};


int main() {
	
	LinkedList l;
	l.addLast(20);
	l.addLast(1);
	l.addLast(12);
	l.addLast(3);
	l.addLast(43);
	l.addLast(29);
	
	l.display();
	l.sort();
	l.display();
	
}