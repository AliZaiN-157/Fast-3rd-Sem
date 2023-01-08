#include <iostream>

using namespace std;

// Check Palindrome in Singly Linked List.

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
	
};

class LinkedList
{
public:
	Node* head;

	LinkedList()
	{
		head = NULL;
	}

	void insert(int d)
	{
		Node* temp = new Node(d);
		temp->next = head;
		head = temp;
	}

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

	bool isPalindrome()
	{
		Node* temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		int arr[count];
		temp = head;
		for (int i = 0; i < count; i++)
		{
			arr[i] = temp->data;
			temp = temp->next;
		}
		int i = 0;
		int j = count - 1;
		while (i < j)
		{
			if (arr[i] != arr[j])
			{
				return false;
			}
			i++;
			j--;
		}
		return true;
	}

};

int main()
{
	LinkedList l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(2);
	l.insert(1);
	l.print();
	cout << l.isPalindrome() << endl;
	return 0;
}


