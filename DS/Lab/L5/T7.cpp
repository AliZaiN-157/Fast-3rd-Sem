#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		next = NULL;
	}
	
	Node() {
		data = 0;
		next = NULL;
	}
};

class LinkedList {
public:
	Node* head;
	Node* tail;

	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	void addNode(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	void printList() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void evenOdd() {
		Node* temp = head;
		Node* even = NULL;
		Node* odd = NULL;
		Node* evenHead = NULL;
		Node* oddHead = NULL;
		while (temp != NULL) {
			if (temp->data % 2 == 0) {
				if (even == NULL) {
					even = temp;
					evenHead = even;
				}
				else {
					even->next = temp;
					even = even->next;
				}
			}
			else {
				if (odd == NULL) {
					odd = temp;
					oddHead = odd;
				}
				else {
					odd->next = temp;
					odd = odd->next;
				}
			}
			temp = temp->next;
		}
		if (even != NULL) {
			even->next = oddHead;
		}
		if (odd != NULL) {
			odd->next = NULL;
		}
		if (evenHead != NULL) {
			head = evenHead;
		}
		else {
			head = oddHead;
		}
	}
};


int main() {
	LinkedList list;
	//list.addNode(17);
	//list.addNode(15);
	list.addNode(8);
	list.addNode(12);
	list.addNode(10);
	//list.addNode(5);
	list.addNode(4);
	//list.addNode(1);
	//list.addNode(7);
	list.addNode(6);
	list.printList();
	list.evenOdd();
	list.printList();
	return 0;
}