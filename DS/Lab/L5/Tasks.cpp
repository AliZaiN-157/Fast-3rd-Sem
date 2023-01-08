#include <iostream>

using namespace std;


class Node
{	
public:
	int data;
	Node* next;
	
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}

	Node()
	{
		data = 0;
		next = NULL;
	}
};

class LinkedList
{
public:
	Node* head;
	Node* tail;

	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	// 1. Insert at the beginning
	void insertAtBeginning(int data)
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
			head = newNode;
		}
	}

	// 2. Insert at the end
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
			tail->next = newNode;
			tail = newNode;
		}
	}

	// 3. Insert at a given position
	void insertAtPosition(int data, int position)
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
			for (int i = 0; i < position - 1; i++)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}

	// 4. Delete from the beginning
	void deleteFromBeginning()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	// 5. Delete from the end.
	void deleteFromEnd()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			Node* temp = head;
			while (temp->next != tail)
			{
				temp = temp->next;
			}
			delete tail;
			tail = temp;
			tail->next = NULL;
		}
	}
	

	// 6. Delete from a given position
	void deleteFromPosition(int position)
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			Node* temp = head;
			for (int i = 0; i < position - 2; i++)
			{
				temp = temp->next;
			}
			Node* temp2 = temp->next;
			temp->next = temp2->next;
			delete temp2;
		}
	}
	
	// 7. Display the list
	void display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	
	// 8. Update a given position
	void update(int data, int position)
	{
		Node* temp = head;
		for (int i = 0; i < position; i++)
		{
			temp = temp->next;
		}
		temp->data = data;
	}

	// 9. Search for a given element
	void search(int data)
	{
		Node* temp = head;
		int position = 0;
		while (temp != NULL)
		{
			if (temp->data == data)
			{
				cout << "Element found at position " << position << endl;
				return;
			}
			temp = temp->next;
			position++;
		}
		cout << "Element not found" << endl;
	}	
};

int main()
{
	LinkedList list;
	list.insertAtEnd(6);
	list.insertAtEnd(7);
	list.insertAtEnd(8);
	list.insertAtEnd(9);
	list.insertAtEnd(10);
	list.insertAtEnd(11);
	list.insertAtEnd(12);
	list.insertAtEnd(13);
	list.display();
	list.insertAtBeginning(1);
	list.insertAtBeginning(2);
	list.insertAtBeginning(3);
	list.insertAtBeginning(4);
	list.insertAtBeginning(5);
	list.display();
	list.insertAtPosition(11, 3);
	list.insertAtPosition(12, 7);
	list.display();
	list.deleteFromBeginning();
	list.deleteFromEnd();
	list.display();
	list.deleteFromPosition(3);
	list.display();
	list.update(14, 3);
	list.update(15, 5);
	list.display();
	list.search(14);
	list.search(16);
	return 0;
}


