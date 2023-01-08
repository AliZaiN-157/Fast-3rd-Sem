#include <iostream>

using namespace std;

// Binary Search in Linked List.

class Node
{
public:
	int data;
	Node* next;
	
	Node(int d)
	{
		data = d;
		next = NULL;
	}
	Node() {
		next = NULL;
		data = 0;
	}
};

class LinkedList
{
public:
	Node* head;

	LinkedList()
	{
		head = NULL;
	}

	// insert Node.
	void insert(int d)
	{
		Node* temp = new Node(d);
		if (head == NULL)
		{
			head = temp;
			return;
		}
		Node* curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}

	// print Linked List.
	void print()
	{
		Node* curr = head;
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}

	// Binary Search in Linked List.
	bool binarySearch(int d)
	{
		Node* curr = head;
		int count = 0;
		while (curr != NULL)
		{
			count++;
			curr = curr->next;
		}
		int mid = count / 2;
		curr = head;
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
	
	// Binary Search with Recursion in Linked List.
	bool binarySearchRecursion(Node* curr, int d)
	{
		if (curr == NULL)
		{
			return false;
		}
		if (curr->data == d)
		{
			return true;
		}
		return binarySearchRecursion(curr->next, d);
	}
};

int main()
{
	LinkedList l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	l.insert(5);
	l.insert(6);
	l.insert(7);
	l.insert(8);
	l.insert(9);
	l.insert(10);
	l.print();
	cout << l.binarySearch(5) << endl;
	cout << l.binarySearch(11) << endl;
	cout << l.binarySearchRecursion(l.head, 5) << endl;
	cout << l.binarySearchRecursion(l.head, 11) << endl;
	return 0;
}