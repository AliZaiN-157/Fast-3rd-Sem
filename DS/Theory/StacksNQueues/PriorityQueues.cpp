#include <iostream>

using namespace std;

// Heaps and Priority queues

class PriorityQueue {
private:
	int* heap;
	int heapSize;
	int heapCapacity;
	void heapify(int i);
	void buildHeap();
	
public:
	PriorityQueue(int capacity);
	~PriorityQueue();
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }
	int getMaximum() { return heap[0]; }
	int extractMax();
	void increaseKey(int i, int key);
	void insert(int key);
	void print();
};

PriorityQueue::PriorityQueue(int capacity) {
	heapSize = 0;
	heapCapacity = capacity;
	heap = new int[heapCapacity];
}

PriorityQueue::~PriorityQueue() {
	delete[] heap;
}

void PriorityQueue::heapify(int i) {
	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l < heapSize && heap[l] > heap[i])
		largest = l;
	if (r < heapSize && heap[r] > heap[largest])
		largest = r;
	if (largest != i) {
		swap(heap[i], heap[largest]);
		heapify(largest);
	}
}

void PriorityQueue::buildHeap() {
	for (int i = heapSize / 2 - 1; i >= 0; i--)
		heapify(i);
}

int PriorityQueue::extractMax() {
	if (heapSize == 0)
		return INT_MIN;
	int root = heap[0];
	if (heapSize > 1) {
		heap[0] = heap[heapSize - 1];
		heapify(0);
	}
	heapSize--;
	return root;
}

void PriorityQueue::increaseKey(int i, int key) {
	heap[i] = key;
	while (i != 0 && heap[parent(i)] < heap[i]) {
		swap(heap[i], heap[parent(i)]);
		i = parent(i);
	}
}

void PriorityQueue::insert(int key) {
	if (heapSize == heapCapacity) {
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	heapSize++;
	int i = heapSize - 1;
	heap[i] = key;
	while (i != 0 && heap[parent(i)] < heap[i]) {
		swap(heap[i], heap[parent(i)]);
		i = parent(i);
	}
}

void PriorityQueue::print() {
	for (int i = 0; i < heapSize; ++i)
		cout << heap[i] << " ";
	cout << endl;
}

int main() {
	PriorityQueue pq(11);
	pq.insert(3);
	pq.insert(2);
	pq.insert(15);
	pq.insert(5);
	pq.insert(4);
	pq.insert(45);
	pq.print();
	cout << "Max: " << pq.getMaximum() << endl;
	cout << "Extract Max: " << pq.extractMax() << endl;
	pq.print();
	pq.increaseKey(2, 1);
	pq.print();
	return 0;
}


	