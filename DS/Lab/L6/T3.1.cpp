#include <iostream>
using namespace std;

// Circular Doubly Linked list

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

class CircularDoublyLinkedList {
public:
	Node* head;
	Node* tail;

	CircularDoublyLinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}

	void insertAtHead(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
			newNode->next = head;	
			newNode->prev = tail;
		}
		else {
			newNode->next = head;
			newNode->prev = tail;
			head->prev = newNode;
			tail->next = newNode;
			head = newNode;
		}
	}

	void insertAtTail(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
			newNode->next = head;
			newNode->prev = tail;
		}
		else {
			newNode->next = head;
			newNode->prev = tail;
			head->prev = newNode;
			tail->next = newNode;
			tail = newNode;
		}
	}

	void insertAtPosition(int data, int position) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
			newNode->next = head;
			newNode->prev = tail;
		}
		else {
			Node* temp = head;
			int count = 1;
			while (count < position - 1) {
				temp = temp->next;
				count++;
			}
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next->prev = newNode;
			temp->next = newNode;
		}
	}

	void deleteAtHead() {
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* temp = head;
			head = head->next;
			head->prev = tail;
			tail->next = head;
			delete temp;
		}
	}

	void deleteAtTail() {
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* temp = tail;
			tail = tail->prev;
			tail->next = head;
			head->prev =