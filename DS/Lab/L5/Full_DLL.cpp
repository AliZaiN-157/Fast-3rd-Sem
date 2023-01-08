#include <iostream>

using namespace std;

// Doubly Linked List

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	
	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}

	Node() {
		this->data = 0;
		this->next = NULL;
		this->prev = NULL;
	}
};

class DoublyLinkedList {
public:
	Node* head;
	Node* tail;
	int size;

	DoublyLinkedList() {
		this->head = NULL;
		this->tail = NULL;
		this->size = 0;
	}

	void add(int data) {
		Node* node = new Node(data);
		if (this->head == NULL) {
			this->head = node;
			this->tail = node;
		}
		else {
			this->tail->next = node;
			node->prev = this->tail;
			this->tail = node;
		}
		this->size++;
	}

	void add(int data, int index) {
		if (index < 0 || index > this->size) {
			cout << "Index out of bounds" << endl;
			return;
		}
		Node* node = new Node(data);
		if (index == 0) {
			node->next = this->head;
			this->head->prev = node;
			this->head = node;
		}
		else if (index == this->size) {
			this->tail->next = node;
			node->prev = this->tail;
			this->tail = node;
		}
		else {
			Node* temp = this->head;
			for (int i = 0; i < index - 1; i++) {
				temp = temp->next;
			}
			node->next = temp->next;
			node->prev = temp;
			temp->next->prev = node;
			temp->next = node;
		}
		this->size++;
	}

	void remove(int index) {
		if (index < 0 || index >= this->size) {
			cout << "Index out of bounds" << endl;
			return;
		}
		if (index == 0) {
			Node* temp = this->head;
			this->head = this->head->next;
			this->head->prev = NULL;
			delete temp;
		}
		else if (index == this->size - 1) {
			Node* temp = this->tail;
			this->tail = this->tail->prev;
			this->tail->next = NULL;
			delete temp;
		}
		else {
			Node* temp = this->head;
			for (int i = 0; i < index - 1; i++) {
				temp = temp->next;
			}
			Node* temp2 = temp->next;
			temp->next = temp->next->next;
			temp->next->prev = temp;
			delete temp2;
		}
		this->size--;
	}

	void print() {
		Node* temp = this->head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void printReverse() {
		Node* temp = this->tail;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->prev;
		}
		cout << endl;
	}

};

