#include <iostream>

using namespace std;

// Given a Circular Singly Linked List(CSLL) with only head as a pointer to access it.
// Write a function that insert a given node at the middle of CSLL. 

class Node {
	
	public:
		int data;
		Node* next;
		Node(int data)
		{
			this->data = data;
			next = NULL;
		}
		
		Node() {
			next = NULL;
			data = 0;
		}
};


class CSLL {

public:
	Node* head;
	CSLL()
	{
		head = NULL;
	}

	void insertAtStart(int data){
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			newNode->next = head;
		}
		else {
			Node* temp = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = head;
			head = newNode;
		}
	}

	void insertAtEnd(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			newNode->next = head;
		}
		else {
			Node* temp = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = head;
		}
	}

	void insertAtMiddle(int data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			newNode->next = head;
			return;
		}

		Node* slow = head;
		Node* fast = head;

		while (fast->next != head && fast->next->next != head)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		newNode->next = slow->next;
		slow->next = newNode;
	}

	// delete at the beginning of the list
	void deleteAtBeg()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		else
		{
			Node* temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}
			temp->next = head->next;
			delete head;
			head = temp->next;
		}
	}

	// delete at the end of the list
	void deleteAtEnd()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		else
		{
			Node* temp = head;
			while (temp->next->next != head)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = head;
		}
	}
	
	// delete at the middle of the list
	void deleteAtMid()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		else
		{
			Node* slow = head;
			Node* fast = head;
			Node* prev = NULL;
			while (fast->next != head && fast->next->next != head)
			{
				prev = slow;
				slow = slow->next;
				fast = fast->next->next;
			}
			prev->next = slow->next;
			delete slow;
		}
	}

	// search
	bool search(int data)
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return false;
		}
		else
		{
			Node* temp = head;
			while (temp->next != head)
			{
				if (temp->data == data)
				{
					return true;
				}
				temp = temp->next;
			}
			if (temp->data == data)
			{
				return true;
			}
			return false;
		}
	}

	// search and return the node
	Node* searchNode(int data)
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return NULL;
		}
		else
		{
			Node* temp = head;
			while (temp->next != head)
			{
				if (temp->data == data)
				{
					return temp;
				}
				temp = temp->next;
			}
			if (temp->data == data)
			{
				return temp;
			}
			return NULL;
		}
	}

	// search and return the position
	int searchPos(int data)
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return -1;
		}
		else
		{
			Node* temp = head;
			int pos = 1;
			while (temp->next != head)
			{
				if (temp->data == data)
				{
					return pos;
				}
				temp = temp->next;
				pos++;
			}
			if (temp->data == data)
			{
				return pos;
			}
			return -1;
		}
	}
	
	// reverse the list
	void reverse()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		else
		{
			Node* prev = NULL;
			Node* curr = head;
			Node* next = NULL;
			do
			{
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			} while (curr != head);
			head->next = prev;
			head = prev;
		}
	}

	void display()
	{
		Node* temp = head;
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}

		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);

		cout << endl;
	}
};


int main() {
	
	CSLL csll;
	csll.insertAtStart(1);
	csll.insertAtStart(2);
	csll.insertAtStart(3);
	csll.insertAtStart(4);
	//csll.insertAtStart(5);
	//csll.insertAtEnd(6);
	csll.insertAtMiddle(5);
	csll.display();
	return 0;
}
