#include <iostream>

using namespace std;

// Consider a Doubly Linked List whose head has been given to you.
// Your job is to eliminate nodes from the SLL in the following manner:

// Initially start from the left of the SLLand remove the first numberand every number afterwards until the end of the SLL is not reached.
// Next step is to start from the right of the SLLand remove the last numberand every other number afterwards until the end of the SLL is not reached
// Keep the same sequence until the final number is not achieved.


class Node
{
public:
	int data;
	Node* next;
	Node* prev;
	Node(int d)
	{
		data = d;
		next = NULL;
		prev = NULL;
	}
	
	Node() {
		next = NULL;
		prev = NULL;
		data = 0;
	}
};

class SLL
{
public:
	Node* head;
	Node* tail;
	SLL()
	{
		head = NULL;
		tail = NULL;
	}

	void insert(int d)
	{
		Node* temp = new Node(d);
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
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

	void remove(Node* temp)
	{
		if (temp == head)
		{
			head = head->next;
			head->prev = NULL;
			delete temp;
		}
		else if (temp == tail)
		{
			tail = tail->prev;
			tail->next = NULL;
			delete temp;
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}

	void eliminate()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			Node* temp2 = temp;
			while (temp2 != NULL)
			{
				temp2 = temp2->next;
				remove(temp);
				temp = temp2;
			}
			temp2 = tail;
			while (temp2 != NULL)
			{
				temp2 = temp2->prev;
				remove(temp);
				temp = temp2;
			}
		}
	}
};

int main()
{
	SLL sll;
	sll.insert(1);
	sll.insert(2);
	sll.insert(3);
	sll.insert(4);
	sll.insert(5);
	sll.insert(6);
	sll.remove(sll.head);
	sll.print();
	return 0;
}




