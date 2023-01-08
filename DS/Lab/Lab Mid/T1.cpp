#include <iostream>

using namespace std;

// Node Class
class Node {
public:
	int data;
	Node* next;
	Node* child;
	
	Node() {
		data = 0;
		next = NULL;
		child = NULL;
	}
	Node(int d) {
		data = d;
		next = NULL;
		child = NULL;
	}
};

// Linked List Class
class LinkedList {
public:
	Node* head;
	
	LinkedList() {
		head = NULL;
	}
	
	// Inserting a Node at the end of the Linked List
	void insert(int d) {
		Node* temp = new Node(d);
		if (head == NULL) {
			head = temp;
		}
		else {
			Node* curr = head;
			while (curr->next != NULL) {
				curr = curr->next;
			}
			curr->next = temp;
		}
	}
	
	// Inserting a Node at the end of the Linked List
	void insertChild(int d) {
		Node* temp = new Node(d);
		if (head == NULL) {
			head = temp;
		}
		else {
			Node* curr = head;
			while (curr->child != NULL) {
				curr = curr->child;
			}
			curr->child = temp;
		}
	}
	
	// Printing the Linked List
	void print() {
		Node* curr = head;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
	
	// Flatenning the Linked List with comments
	void flatten() {
		Node* curr = head; // Current Node
		while (curr != NULL) { // Looping through the Linked List
			if (curr->child != NULL) { // If the current Node has a child
				Node* temp = curr->next; // Saving the next Node
				curr->next = curr->child; // Setting the next Node to the child
				curr->child = NULL; // Setting the child to NULL
				Node* curr2 = curr->next; // Setting a new current Node to the child
				while (curr2->next != NULL) { // Looping through the child
					curr2 = curr2->next; // Moving to the next Node
				}
				curr2->next = temp; // Setting the next Node of the child to the saved Node
			}
			curr = curr->next; // Moving to the next Node
		}
	}
	
	// sorting the Linked List
	void sort() {
		Node* curr = head;
		while (curr != NULL) {
			Node* curr2 = curr->next;
			while (curr2 != NULL) {
				if (curr->data > curr2->data) {
					int temp = curr->data;
					curr->data = curr2->data;
					curr2->data = temp;
				}
				curr2 = curr2->next;
			}
			curr = curr->next;
		}
	}

	// Remove Duplicates from the Linked List
	void removeDuplicates() {
		Node* curr = head; // Current Node
		while (curr != NULL) { // Looping through the Linked List
			Node* curr2 = curr->next; // Setting a new current Node to the next Node
			while (curr2 != NULL) {	// Looping through the Linked List
				if (curr->data == curr2->data) { // If the current Node is equal to the new current Node
					Node* temp = curr2->next; // Saving the next Node
					curr->next = temp; // Setting the next Node to the saved Node
					curr2 = temp; // Setting the new current Node to the saved Node
				}
				else {
					curr2 = curr2->next;
				}
			}
			curr = curr->next;
		}
	}

	// Check Palindrome of the Linked List
	bool checkPalindrome() {
		Node* curr = head; // Current Node
		int size = 0; // Size of the Linked List
		while (curr != NULL) { // Looping through the Linked List
			size++; // Incrementing the size
			curr = curr->next; // Moving to the next Node
		}
		curr = head; // Setting the current Node to the head
		int* arr = new int[size]; // Creating an array
		for (int i = 0; i < size; i++) { // Looping through the array
			arr[i] = curr->data; // Setting the array to the data of the Linked List
			curr = curr->next; // Moving to the next Node
		}
		for (int i = 0; i < size / 2; i++) { // Looping through the array
			if (arr[i] != arr[size - i - 1]) { // If the array is not a palindrome
				return false; // Return false
			}
		}
		return true; // Return true
	}

	// Delete Zero Sum
	void deleteZeroSum() {
		Node* temp = head;
		Node* prev = NULL;
		while (temp != NULL) {
			int sum = 0;
			Node* temp2 = temp;
			while (temp2 != NULL) {
				sum += temp2->data;
				if (sum == 0) {
					if (prev == NULL) {
						head = temp2->next;
					}
					else {
						prev->next = temp2->next;
					}
					temp = temp2->next;
					break;
				}
				temp2 = temp2->next;
			}
			if (sum != 0) {
				prev = temp;
				temp = temp->next;
			}
		}
	}

	// 4.Add 1 to a number represented as a linked list
	// For example 1999 is represented as(1-> 9-> 9 -> 9) and adding 1 to it should change it to(2->0->0->0)
	
	void addOne() {
		Node* curr = head;
		int size = 0;
		while (curr != NULL) {
			size++;
			curr = curr->next;
		}
		int* arr = new int[size];
		curr = head;
		int i = 0;
		while (curr != NULL) {
			arr[i] = curr->data;
			i++;
			curr = curr->next;
		}
		int carry = 1;
		for (int i = size - 1; i >= 0; i--) {
			int sum = arr[i] + carry;
			arr[i] = sum % 10;
			carry = sum / 10;
		}
		if (carry != 0) {
			int* arr2 = new int[size + 1];
			arr2[0] = carry;
			for (int i = 0; i < size; i++) {
				arr2[i + 1] = arr[i];
			}
			head = NULL;
			for (int i = 0; i < size + 1; i++) {
				insert(arr2[i]);
			}
		}
		else {
			head = NULL;
			for (int i = 0; i < size; i++) {
				insert(arr[i]);
			}
		}
	}
	
	// Detect and remove loop in linked list given only the head node
	void removeLoop(Node* loop) {
		Node* ptr1 = loop;
		Node* ptr2 = loop;
		int k = 1;
		while (ptr1->next != ptr2) {
			ptr1 = ptr1->next;
			k++;
		}
		ptr1 = head;
		ptr2 = head;
		for (int i = 0; i < k; i++) {
			ptr2 = ptr2->next;
		}
		while (ptr1 != ptr2) {
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		while (ptr2->next != ptr1) {
			ptr2 = ptr2->next;
		}
		ptr2->next = NULL;
	}
	
	void detectAndRemoveLoop() {
		Node* slow = head;
		Node* fast = head;
		while (slow != NULL && fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				//removeLoop(slow);
				slow->next->next = NULL;
				return;
			}
		}
	}

	// Find nth node from the end of linked list.
	void findNthNode(int n) {
		Node* curr = head;
		int size = 0;
		while (curr != NULL) {
			size++;
			curr = curr->next;
		}
		curr = head;
		for (int i = 0; i < size - n; i++) {
			curr = curr->next;
		}
		cout << curr->data << endl;
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
	
};


int main() {
	LinkedList ll;
	// Inserting Nodes in the Linked List
	ll.insert(5);
	ll.insert(10);
	ll.insert(19);
	ll.insert(28);
	
	// Inserting Nodes in the Child Linked List
	ll.head->child = new Node(7);
	ll.head->child->child = new Node(8);
	ll.head->child->child->child = new Node(30);
	
	// Inserting Nodes in the Child Linked List
	ll.head->next->child = new Node(20);
	
	// Inserting Nodes in the Child Linked List
	ll.head->next->next->child = new Node(22);
	ll.head->next->next->child->child = new Node(50);

	// Inserting Nodes in the Child Linked List
	ll.head->next->next->next->child = new Node(35);
	ll.head->next->next->next->child->child = new Node(40);
	ll.head->next->next->next->child->child->child = new Node(45);
	
	// Flatenning the Linked List
	ll.flatten();
	ll.sort();
	ll.print();

	cout << endl << endl;
	
	LinkedList ll2;
	// Inserting Nodes in the Linked List
	ll2.insert(1);
	ll2.insert(3);
	ll2.insert(5);
	ll2.insert(4);
	ll2.insert(5);
	ll2.insert(3);
	ll2.insert(1);
	
	// find Nth Node from the end of Linked List
	//ll2.findNthNode(3);
	
	cout << "\nDelete Sum" << endl;
	/*ll2.deleteZeroSum();
	ll2.print();*/

	cout << "\nCheck Palindrome of the Linked List" << endl;
	cout << ll2.checkPalindrome() << endl;

	cout << "\nAdd 1 to a number represented as a linked list" << endl;
	LinkedList ll3;
	ll3.insert(1);
	ll3.insert(9);
	ll3.insert(9);
	ll3.insert(9);
	
	// Adding 1 to a number represented as a linked list
	//ll3.addOne2();
	ll3.print();

	cout << "\nRemoving Duplicates from the Linked List" << endl;
	//ll3.removeDuplicates();
	// ll3.print();

	cout << "\nDelete last occurrence of an item from linked list" << endl;
	ll3.deleteLastOccurrence(9);
	ll3.print();

	
	cout << "\nDetect and remove loop in linked list given only the head node" << endl;
	LinkedList ll4;
	ll4.insert(1);
	ll4.insert(2);
	ll4.insert(3);
	ll4.insert(4);
	ll4.insert(5);
	
	// Creating a loop in the Linked List
	ll4.head->next->next->next->next->next = ll4.head->next->next;
	
	// Detecting and removing the loop
	ll4.detectAndRemoveLoop();

	ll4.print();

}