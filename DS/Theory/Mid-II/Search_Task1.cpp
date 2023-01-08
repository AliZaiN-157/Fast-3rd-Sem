#include <iostream>

using namespace std;

// Binary Search on Linked List

// Node Class
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
		next = NULL;
	}
};

// Linked List Class
class LinkedList {
public:
	Node* head;

	LinkedList() {
		head = NULL;
	}

	// Insert from head
	void insertFromBegin(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	// Display the list
	void display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	// Get Count
	int getCount() {
		Node* temp = head;
		int count = 0;
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}
		return count;
	}

	// Binary Search on Linked List
	int binarySearch(int data) {
		int count = getCount();
		int low = 0;
		int high = count - 1;
		int mid = 0;
		Node* temp = head;
		while (low <= high) {
			mid = (low + high) / 2;
			for (int i = 0; i < mid; i++) {
				temp = temp->next;
			}
			if (temp->data == data) {
				return mid;
			}
			else if (temp->data > data) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
			temp = head;
		}
		return -1;
	}

	bool binarySearch2(int d)
	{
		int count = getCount();
		int mid = count / 2;
		Node* curr = head;
		for (int i = 0; i < mid; i++)
		{
			curr = curr->next;
		}
		if (curr->data == d)
		{
			return true;
		}
		else if (curr->data > d)
		{
			Node* temp = head;
			while (temp != curr)
			{
				if (temp->data == d)
				{
					return true;
				}
				temp = temp->next;
			}
		}
		else
		{
			Node* temp = curr;
			while (temp != NULL)
			{
				if (temp->data == d)
				{
					return true;
				}
				temp = temp->next;
			}
		}
		return false;
	}

};

int main() {
	LinkedList list;
	list.insertFromBegin(10);
	list.insertFromBegin(9);
	list.insertFromBegin(8);
	list.insertFromBegin(7);
	list.insertFromBegin(6);
	list.insertFromBegin(5);
	list.insertFromBegin(4);
	list.insertFromBegin(3);
	list.insertFromBegin(2);
	list.insertFromBegin(1);
	list.display();

	cout << list.binarySearch2(6) << endl;

	cout << "Enter the element to be searched: ";
	int data;
	cin >> data;
	int find = list.binarySearch(data);
	if (find == -1) {
		cout << "Not Found" << endl;
	}
	else {
		cout << "Found at index " << find << endl;
	}
	
	return 0;
}