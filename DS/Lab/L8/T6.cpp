#include <iostream>

using namespace std;

// Implement the Elementary implementation of Priority queue using linked list as explain in Figure “Sequence of Operation in Priority Queue”.

class Node {
public:
	int data;
	int priority;
	Node* next;
	
	Node() {
		data = 0;
		priority = 0;
		next = NULL;
	}

	Node(int d, int p) {
		data = d;
		priority = p;
		next = NULL;
	}
};

class PriorityQueue {
private:
	Node* front;
	Node* rear;
public:
	PriorityQueue() {
		front = NULL;
		rear = NULL;
	}

	void enqueue(int d, int p) {
		Node* newNode = new Node(d, p);
		if (front == NULL) {
			front = newNode;
			rear = newNode;
		}
		else {
			Node* temp = front;
			while (temp->next != NULL && temp->next->priority < p) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}

	void dequeue() {
		if (front == NULL) {
			cout << "Queue is empty" << endl;
		}
		else {
			Node* temp = front;
			front = front->next;
			delete temp;
		}
	}

	void display() {
		if (front == NULL) {
			cout << "Queue is empty" << endl;
		}
		else {
			Node* temp = front;
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
};

int main() {
	PriorityQueue q;
	q.enqueue(1, 1);
	q.enqueue(2, 2);
	q.enqueue(3, 3);
	q.enqueue(4, 1);
	q.enqueue(5, 5);
	q.display();
	q.dequeue();
	q.display();
//	q.dequeue();
//	q.display();
//	q.dequeue();
//	q.display();
//	q.dequeue();
//	q.display();
//	q.dequeue();
//	q.display();
	return 0;
}