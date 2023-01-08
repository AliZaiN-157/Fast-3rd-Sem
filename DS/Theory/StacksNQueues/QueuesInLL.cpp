#include <iostream>

using namespace std;

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

class Queue
{
	Node* head;
	Node* tail;
	
public:
	Queue()
	{
		head = NULL;
		tail = NULL;
	}

	void enqueue(int d)
	{
		if (head == NULL)
		{
			head = new Node(d);
			tail = head;
		}
		else
		{
			tail->next = new Node(d);
			tail = tail->next;
		}
	}

	void dequeue()
	{
		if (head == NULL)
		{
			cout << "Queue is empty" << endl;
			return;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	int front()
	{
		if (head == NULL)
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		else
		{
			return head->data;
		}
	}

	bool isEmpty()
	{
		return head == NULL;
	}
};

int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);

	while (!q.isEmpty())
	{
		cout << q.front() << " ";
		q.dequeue();
	}

}
