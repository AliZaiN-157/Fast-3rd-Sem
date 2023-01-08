#include <iostream>

using namespace std;

// Create Doubly Linked List.

class Node
{
public:
	int data;
	Node* next;
	Node* prev;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}

	Node()
	{
		this->next = NULL;
		this->prev = NULL;
		data = 0;
	}
};

class DoublyLinkedList
{
public:
	Node* head;

	DoublyLinkedList()
	{
		head = NULL;
	}

	// insert at the beginning of the list
	void insertAtBeginning(int data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	// insert at the end of the list
	void insertAtEnd(int data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
	
	// insert at the middle of the list
	void insertAtMiddle(int data, int position)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		Node* temp = head;
		for (int i = 0; i < position - 1; i++)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next = newNode;
		newNode->next->prev = newNode;
	}
	
	// delete at the beginning of the list
	void deleteAtBeginning()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		Node* temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
	}

	// delete at the end of the list
	void deleteAtEnd()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->prev->next = NULL;
		delete temp;
	}
	
	// delete from any position of the list
	void deleteFromPos(int position)
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		Node* temp = head;
		for (int i = 0; i < position - 1; i++)
		{
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
	
	// print the list
	
	void printList()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	
	// sort the list
	void sort()
	{
		Node* temp = head;
		Node* temp2 = head;
		while (temp != NULL)
		{
			while (temp2 != NULL)
			{
				if (temp->data < temp2->data)
				{
					int tempData = temp->data;
					temp->data = temp2->data;
					temp2->data = tempData;
				}
				temp2 = temp2->next;
			}
			temp2 = head;
			temp = temp->next;
		}
	}
	
	// merge two lists
	
	void merge(DoublyLinkedList list)
	{
		Node* temp = list.head;
		while (temp != NULL)
		{
			insertAtEnd(temp->data);
			temp = temp->next;
		}
	}
};

int main(){

	DoublyLinkedList dll;
	dll.insertAtBeginning(11);
	dll.insertAtBeginning(2);
	dll.insertAtBeginning(23);
	dll.insertAtBeginning(17);
	dll.insertAtBeginning(5);
	dll.insertAtEnd(1);
	dll.insertAtEnd(12);
	dll.insertAtEnd(3);
	dll.insertAtMiddle(10, 3);

	dll.printList();

	dll.deleteAtBeginning();
	dll.deleteAtEnd();
	dll.deleteFromPos(3);
	
	dll.printList();
	
	cout << endl << "Task#4: " << endl;
	
	DoublyLinkedList N, M;
	N.insertAtBeginning(11);
	N.insertAtBeginning(27);
	N.insertAtBeginning(3);
	N.insertAtBeginning(13);
	N.insertAtBeginning(5);

	cout << "List N: ";
	N.printList();
	
	M.insertAtBeginning(6);
	M.insertAtBeginning(34);
	M.insertAtBeginning(25);
	M.insertAtBeginning(17);
	M.insertAtBeginning(9);

	cout << "List M: ";
	M.printList();
	
	cout << "Merged List: ";
	N.merge(M);
	N.printList();
	
	N.sort();
	
	cout << "Sorted List: ";
	N.printList();
	
}
