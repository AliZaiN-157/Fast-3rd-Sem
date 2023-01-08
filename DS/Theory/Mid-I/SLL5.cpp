#include <iostream>

using namespace std;

// Merger two linked list.

class Node {
public:
	int data;
	Node* next;
	
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	
	Node() {
		data = 0;
		this->next = NULL;
	}
};


class LinkedList {
public:
	Node* head;

	LinkedList() {
		head = NULL;
	}

	void insert(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	void print() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void merge(LinkedList* list) {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = list->head;
	}
};


int main() {
	LinkedList* list1 = new LinkedList();
	LinkedList* list2 = new LinkedList();
	list1->insert(1);
	list1->insert(2);
	list1->insert(3);
	list1->insert(4);
	list1->insert(5);
	list1->insert(6);
	list1->insert(7);
	list1->insert(8);
	list1->insert(9);
	list1->insert(10);
	list1->print();
	list2->insert(11);
	list2->insert(12);
	list2->insert(13);
	list2->insert(14);
	list2->insert(15);
	list2->insert(16);
	list2->insert(17);
	list2->insert(18);
	list2->insert(19);
	list2->insert(20);
	list2->print();
	list1->merge(list2);
	list1->print();
	return 0;
}