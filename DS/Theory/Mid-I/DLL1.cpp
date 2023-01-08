#include <iostream>

using namespace std;

// Write a function for DoublyLinkedList<T> class, which decide for a given node pointer, 
// if the node contains a pair of predecessors and successors or not?
// bool hasPairsOfPredecessorNSuccessor(DNode<T> *PPSNodes);


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

	void insert(int data)
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

	bool hasPairsOfPredecessorNSuccessor(Node* PPSNodes)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->prev != NULL && temp->next != NULL)
			{
				PPSNodes = temp;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
};

int main()
{
	DoublyLinkedList dll;
	dll.insert(1);
	dll.insert(2);
	dll.insert(3);
	dll.insert(4);
	dll.insert(5);
	dll.insert(6);
	dll.insert(7);
	dll.insert(8);
	dll.insert(9);
	dll.insert(10);
	dll.print();

	Node* PPSNodes = new Node();
	if (dll.hasPairsOfPredecessorNSuccessor(PPSNodes))
	{
		cout << "The node with pairs of predecessor and successor is: " << PPSNodes->data << endl;
	}
	else
	{
		cout << "There is no node with pairs of predecessor and successor." << endl;
	}

}