#include <iostream>

using namespace std;

// Solve Quadratic Equation using linked List.

class Node {
public:
	int constant;
	string base;
	int power;
	Node* next;

	Node()
	{
		constant = 0;
		base = "";
		power = 0;
		next = NULL;
	}
	Node(int constant, string base, int power)
	{
		this->constant = constant;
		this->base = base;
		this->power = power;
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
	
	void addNode(int constant, string base, int power)
	{
		Node* newNode = new Node(constant, base, power);
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			Node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	void display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->constant << temp->base << "^" << temp->power << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void solve()
	{
		Node* temp = head;
		int a, b, c;
		while (temp != NULL)
		{
			if (temp->power == 2)
			{
				a = temp->constant;
			}
			else if (temp->power == 1)
			{
				b = temp->constant;
			}
			else if (temp->power == 0)
			{
				c = temp->constant;
			}
			temp = temp->next;
		}
		int d = (b * b) - (4 * a * c);
		if (d > 0)
		{
			cout << "Roots are real and distinct" << endl;
			cout << "Roots are: " << (-b + sqrt(d)) / (2 * a) << " and " << (-b - sqrt(d)) / (2 * a) << endl;
		}
		else if (d == 0)
		{
			cout << "Roots are real and equal" << endl;
			cout << "Roots are: " << (-b + sqrt(d)) / (2 * a) << " and " << (-b - sqrt(d)) / (2 * a) << endl;
		}
		else
		{
			cout << "Roots are imaginary" << endl;
			cout << "Roots are: " << (-b + sqrt(-d)) / (2 * a) << "i and " << (-b - sqrt(-d)) / (2 * a) << "i" << endl;
		}
	}

	// Sum of same bases and powers
	void sum()
	{
		Node* temp = head;
		Node* temp2 = head;
		while (temp != NULL)
		{
			temp2 = temp->next;
			while (temp2 != NULL)
			{
				if (temp->base == temp2->base && temp->power == temp2->power)
				{
					temp->constant += temp2->constant;
					temp2->constant = 0;
				}
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
	}
	
	// Derivative of the equation
	void derivative()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			temp->constant *= temp->power;
			temp->power--;
			temp = temp->next;
		}
	}	
	
	// sum of two Linked Lists
	void sum1(LinkedList l2)
	{
		Node* temp = head;
		Node* temp2 = l2.head;
		while (temp != NULL)
		{
			temp2 = l2.head;
			while (temp2 != NULL)
			{
				if (temp->base == temp2->base && temp->power == temp2->power)
				{
					temp->constant += temp2->constant;
					temp2->constant = 0;
				}
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
	}
};

int main()
{

	LinkedList list;
	list.addNode(4, "x", 7);
	list.addNode(2, "x", 6);
	list.addNode(-1, "x", 3);
	list.addNode(4, "x", 2);
	list.addNode(3, "x", 0);
	list.display();

	LinkedList list2;
	list2.addNode(2, "x", 6);
	list2.addNode(3, "x", 2);
	list2.addNode(-2, "x", 0);
	list2.display();
	
	cout << "Sum of same bases: " << endl;
	list.sum1(list2);
	list.display();

	cout << "Derivative of the equation: " << endl;
	list.derivative();
	list.display();
	
	//list.solve();
	return 0;
}

