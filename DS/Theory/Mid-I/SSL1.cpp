#include <iostream>

using namespace std;

// reorder the singly linked list
// L0 -> L1 -> L2 .... -> Ln
// L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 ...

class Node {
public:
	int data;
	Node* next;
	Node(int d) : data(d), next(NULL) {}
};

class LinkedList {
public:
	Node* head;
	LinkedList() : head(NULL) {}
	void insert(int d) {
		Node* n = new Node(d);
		if (head == NULL) {
			head = n;
			return;
		}
		Node* p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = n;
	}
	void print() {
		Node* p = head;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	

	// reorder the singly linked list
	// L0 -> L1 -> L2 .... -> Ln
	// L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 ...
	void reorder() {
		if (head == NULL || head->next == NULL) {
			return;
		}
		Node* p = head;
		Node* q = head;
		while (q->next != NULL && q->next->next != NULL) {
			p = p->next;
			q = q->next->next;
		}
		Node* mid = p;
		Node* tail = p->next;
		mid->next = NULL;
		Node* prev = NULL;
		while (tail != NULL) { // 4 -> 5 -> 6 
			Node* next = tail->next;
			tail->next = prev; // NULL <- 4 <- 5 <- 6
			prev = tail; 
			tail = next; 
		}
		Node* p1 = head;
		Node* p2 = prev;
		while (p1 != NULL && p2 != NULL) {
			Node* next1 = p1->next;
			Node* next2 = p2->next;
			p1->next = p2;
			p2->next = next1;
			p1 = next1;
			p2 = next2;
		}
	}
};

int main() {
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
	l.reorder();
	l.print();
	return 0;
}
