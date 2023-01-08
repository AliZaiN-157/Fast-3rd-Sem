#include <iostream>

using namespace std;

// Linked list based queues

class Node {
public:
	int data;
	Node* next;
	
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int d) {
		data = d;
		next = NULL;
	}
};


class Queue {
private:
	int size;
	int capacity;
	Node* front;
	Node* rear;
public:
	Queue() {
		size = 0;
		capacity = 0;
		front = NULL;
		rear = NULL;
	}
	Queue(int c) {
		size = 0;
		capacity = c;
		front = NULL;
		rear = NULL;
	}

	void enqueue(int d) {
		if (size == capacity) {
			cout << "Queue is full" << endl;
			return;
		}
		Node* newNode = new Node(d);
		if (size == 0) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		size++;
	}

	int dequeue() {
		if (size == 0) {
			cout << "Queue is empty" << endl;
			return -1;
		}
		int d = front->data;
		Node* temp = front;
		front = front->next;
		delete temp;
		size--;
		return d;
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}

	void print() {
		Node* temp = front;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	Queue q(5);
	
	if(q.isEmpty())
		cout << "Queue is empty" << endl;
	else
		cout << "Queue is not empty" << endl;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.print();

	if (q.isFull())
		cout << "Queue is full" << endl;
	else
		cout << "Queue is not full" << endl;
	
	q.dequeue();
	q.dequeue();
	q.print();
	q.enqueue(6);
	q.enqueue(7);
	q.print();
	return 0;
}

