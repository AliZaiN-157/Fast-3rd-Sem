#include <iostream>

using namespace std;

// Heap Tree

class HeapTree {
private:
	int* heap;
	int size;
	int capacity;
	
public:
	HeapTree(int capacity) {
		this->capacity = capacity;
		this->size = 0;
		this->heap = new int[capacity];
	}

	void insert(int data) {
		if (size == capacity) {
			cout << "Heap is full" << endl;
			return;
		}
		heap[size] = data;
		int current = size;
		int parent = (current - 1) / 2;
		while (current > 0 && heap[current] > heap[parent]) {
			int temp = heap[current];
			heap[current] = heap[parent];
			heap[parent] = temp;
			current = parent;
			parent = (current - 1) / 2;
		}
		size++;
	}

	void remove() {
		if (size == 0) {
			cout << "Heap is empty" << endl;
			return;
		}
		heap[0] = heap[size - 1];
		size--;
		int current = 0;
		int left = 2 * current + 1;
		int right = 2 * current + 2;
		while (left < size) {
			int max = current;
			if (heap[max] < heap[left]) {
				max = left;
			}
			if (right < size && heap[max] < heap[right]) {
				max = right;
			}
			if (max == current) {
				break;
			}
			int temp = heap[current];
			heap[current] = heap[max];
			heap[max] = temp;
			current = max;
			left = 2 * current + 1;
			right = 2 * current + 2;
		}
	}

	// remove specific position
	void remove(int position) {
		if (size == 0) {
			cout << "Heap is empty" << endl;
			return;
		}
		heap[position] = heap[size - 1];
		size--;
		int current = position;
		int left = 2 * current + 1;
		int right = 2 * current + 2;
		while (left < size) {
			int max = current;
			if (heap[max] < heap[left]) {
				max = left;
			}
			if (right < size && heap[max] < heap[right]) {
				max = right;
			}
			if (max == current) {
				break;
			}
			int temp = heap[current];
			heap[current] = heap[max];
			heap[max] = temp;
			current = max;
			left = 2 * current + 1;
			right = 2 * current + 2;
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << heap[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	HeapTree heap(10);
	heap.insert(10);
	heap.insert(5);
	heap.insert(30);
	heap.insert(20);
	heap.insert(35);
	heap.insert(15);
	heap.insert(40);
	heap.insert(25);
	heap.insert(45);
	heap.insert(50);
	heap.print();
	

}