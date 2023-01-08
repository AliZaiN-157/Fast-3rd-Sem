#include <iostream>

using namespace std;

// Create a queue using an array and perform all the operations of the queue in C++.

class Queue
{
	int size;
	int capacity;
	int* array;
	
public:
	Queue(int capacity)
	{
		this->capacity = capacity;
		array = new int[capacity];
		size = 0;
	}

	void enqueue(int data)
	{
		if (size == capacity)
		{
			cout << "Queue is full" << endl;
			return;
		}
		array[size] = data;
		size++;
	}

	void dequeue()
	{
		if (size == 0)
		{
			cout << "Queue is empty" << endl;
			return;
		}
		for (int i = 0; i < size - 1; i++)
		{
			array[i] = array[i + 1];
		}
		size--;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}

	bool isFull()
	{
		return size == capacity;
	}
	
	bool isEmpty()
	{
		return size == 0;
	}
	
};

int main()
{
	Queue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.print();
	q.dequeue();
	q.print();
	q.enqueue(6);
	q.dequeue();
	q.print();
	return 0;
}

