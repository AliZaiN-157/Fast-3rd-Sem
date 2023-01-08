#include <iostream>

using namespace std;

class Queue
{
private:
	int* arr;
	int size;
	int front;
	int rear;
	int count;
	
public:
	Queue(int size)
	{
		this->size = size;
		arr = new int[size];
		front = 0;
		rear = -1;
		count = 0;
	}

	void enqueue(int data)
	{
		if (count == size)
		{
			cout << "Queue is full" << endl;
			return;
		}
		rear = (rear + 1) % size;
		arr[rear] = data;
		count++;
	}

	int dequeue()
	{
		if (count == 0)
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		int data = arr[front];
		front = (front + 1) % size;
		count--;
		return data;
	}

	int peek()
	{
		if (count == 0)
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		return arr[front];
	}

	int Size()
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	bool isFull()
	{
		return count == size;
	}

	void display()
	{
		if (count == 0)
		{
			cout << "Queue is empty" << endl;
			return;
		}
		for (int i = 0; i < count; i++)
		{
			cout << arr[(front + i) % size] << " ";
		}
		cout << endl;
	}
};

int main()
{
	Queue q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	q.display();
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	q.display();
	cout << q.peek() << endl;
	cout << q.isEmpty() << endl;
	cout << q.isFull() << endl;
	return 0;
}