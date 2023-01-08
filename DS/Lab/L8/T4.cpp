#include <iostream>

using namespace std;

// Array Based Queues

class Queue {
private:
	int* arr;
	int front;
	int rear;
	int size;
	
public:
	Queue(int size) {
		this->size = size;
		front = -1;
		rear = -1;
		arr = new int[size];
	}

	void enqueue(int data) {
		if (rear == size - 1) {
			cout << "Queue is full" << endl;
		}
		else {
			rear++;
			arr[rear] = data;
			if (front == -1) {
				front = 0;
			}
		}
	}

	int dequeue() {
		int data = 0;
		if (front == -1 || front > rear) {
			cout << "Queue is empty" << endl;
		}
		else {
			data = arr[front];
			front++;
		}
		return data;
	}

	int peek() {
		int data = 0;
		if (front == -1 || front > rear) {
			cout << "Queue is empty" << endl;
		}
		else {
			data = arr[front];
		}
		return data;
	}

	bool isEmpty() {
		return (front == -1 || front > rear);
	}

	bool isFull() {
		return (rear == size - 1);
	}

	void display() {
		if (front == -1 || front > rear) {
			cout << "Queue is empty" << endl;
		}
		else {
			for (int i = front; i <= rear; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	Queue q(5);
	if (q.isEmpty())
		cout << "Queue is empty" << endl;
	else
		cout << "Queue is not empty" << endl;
	
	
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.display();
	q.dequeue();
	q.display();
	q.enqueue(6);
	q.display();

	return 0;
}