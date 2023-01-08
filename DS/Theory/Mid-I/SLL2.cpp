#include <iostream>

using namespace std;

// Remove Middle Node from singly linked list.

class Node {
public:
	int data;
	Node* next;
	Node(int d) {
		data = d;
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
	LinkedList() {
		head = NULL;
	}

	void insert(int d) {
		Node* temp = new Node(d);
		if (head == NULL) {
			head = temp;
			return;
		}
		Node* curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = temp;
	}

	void print() {
		Node* curr = head;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}

	/*void removeMiddleNode(Node* n) {
		if (n == NULL || n->next == NULL) {
			return;
		}
		Node* next = n->next;
		n->data = next->data;
		n->next = next->next;
		delete next;
	}*/

	// remove Middle Node without parameter.
	
	void removeMiddleNode() {
		if (head == NULL || head->next == NULL) {
			return;
		}
		Node* slow = head;
		Node* fast = head;
		Node* prev = NULL;
		while (fast != NULL && fast->next != NULL) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = slow->next;
		delete slow;
	}
};


int main() {
	
	LinkedList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.removeMiddleNode();
	list.print();
}