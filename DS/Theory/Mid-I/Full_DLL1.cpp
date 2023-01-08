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
	Node* tail;

	DoublyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	//1. insert at the beginning of the list
	void insertAtBeg(int data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	//2. insert at the end of the list
	void insertAtEnd(int data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	
	//3. insert at the middle of the list
	void insertAtMid(int data, int pos)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			Node* temp = head;
			for (int i = 0; i < pos - 1; i++)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next->prev = newNode;
			temp->next = newNode;
			newNode->prev = temp;
		}
	}
	
	//4. delete at the beginning of the list
	void deleteAtBeg()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
		}
	}

	//5. delete at the end of the list
	void deleteAtEnd()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			Node* temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete temp;
		}
	}
	
	//6. delete at the middle of the list
	
	void deleteAtMid(int pos)
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			Node* temp = head;
			for (int i = 0; i < pos - 1; i++)
			{
				temp = temp->next;
			}
			temp->next = temp->next->next;
			temp->next->prev = temp;
		}
	}
	
	//7. print the list
	
	void print()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	//8. reverse the list
	
	void reverse()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			Node* temp1 = temp->next;
			temp->next = temp->prev;
			temp->prev = temp1;
			temp = temp1;
		}
		temp = head;
		head = tail;
		tail = temp;
	}

	//9. search an element in the list
	
	void search(int data)
	{
		Node* temp = head;
		int pos = 0;
		while (temp != NULL)
		{
			if (temp->data == data)
			{
				cout << "Element found at position " << pos << endl;
				return;
			}
			temp = temp->next;
			pos++;
		}
		cout << "Element not found" << endl;
	}
	
	//10. sort the list
	
	void sort()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			Node* temp1 = temp->next;
			while (temp1 != NULL)
			{
				if (temp->data > temp1->data)
				{
					int temp2 = temp->data;
					temp->data = temp1->data;
					temp1->data = temp2;
				}
				temp1 = temp1->next;
			}
			temp = temp->next;
		}
	}
	
	//11. merge two lists
	
	void merge(DoublyLinkedList list)
	{
		Node* temp = list.head;
		while (temp != NULL)
		{
			insertAtEnd(temp->data);
			temp = temp->next;
		}
	}
	
	//12. split the list
	
	void split(DoublyLinkedList& list1, DoublyLinkedList& list2)
	{
		Node* temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		temp = head;
		for (int i = 0; i < count / 2; i++)
		{
			list1.insertAtEnd(temp->data);
			temp = temp->next;
		}
		for (int i = count / 2; i < count; i++)
		{
			list2.insertAtEnd(temp->data);
			temp = temp->next;
		}
	}
	
	//13. remove duplicates
	
	void removeDuplicates()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			Node* temp1 = temp->next;
			while (temp1 != NULL)
			{
				if (temp->data == temp1->data)
				{
					temp1->prev->next = temp1->next;
					temp1->next->prev = temp1->prev;
				}
				temp1 = temp1->next;
			}
			temp = temp->next;
		}
	}
};