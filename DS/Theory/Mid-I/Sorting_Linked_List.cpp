#include <iostream>

using namespace std;

// Node class
class Node {
public:
	int data;
	Node* next;
	
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

// Linked List class
class LinkedList {
public:
	Node* head;

	LinkedList() {
		head = NULL;
	}

	// Insert a node at the end of the list
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

	// Print the list
	void print() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	// Merge Sort Linked List.
	
	// Get Middle
	Node* getMiddle(Node* h) {
		if (h == NULL) {
			return h;
		}
		Node* slow = h;
		Node* fast = h;
		while (fast->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
	
	// Merge
	Node* merge(Node* a, Node* b) {
		Node* result = NULL;
		if (a == NULL) {
			return b;
		}
		else if (b == NULL) {
			return a;
		}
		if (a->data <= b->data) {
			result = a;
			result->next = merge(a->next, b);
		}
		else {
			result = b;
			result->next = merge(a, b->next);
		}
		return result;
	}
	
	// Merge Sort
	Node* mergeSort(Node* h) {
		if (h == NULL || h->next == NULL) {
			return h;
		}
		Node* middle = getMiddle(h);
		Node* nextofmiddle = middle->next;
		middle->next = NULL;
		Node* left = mergeSort(h);
		Node* right = mergeSort(nextofmiddle);
		Node* sortedlist = merge(left, right);
		return sortedlist;
	}
	
	// Quick Sort Linked List.
	
	// Get Tail
	Node* getTail(Node* cur) {
		while (cur != NULL && cur->next != NULL) {
			cur = cur->next;
		}
		return cur;
	}
	
	// Partition
	Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
		Node* pivot = end;
		Node* prev = NULL;
		Node* cur = head;
		Node* tail = pivot;
		while (cur != pivot) {
			if (cur->data < pivot->data) {
				if ((*newHead) == NULL) {
					(*newHead) = cur;
				}
				prev = cur;
				cur = cur->next;
			}
			else {
				if (prev) {
					prev->next = cur->next;
				}
				Node* tmp = cur->next;
				cur->next = NULL;
				tail->next = cur;
				tail = cur;
				cur = tmp;
			}
		}
		if ((*newHead) == NULL) {
			(*newHead) = pivot;
		}
		(*newEnd) = tail;
		return pivot;
	}
	
	// Quick Sort
	Node* quickSortRecur(Node* head, Node* end) {
		if (!head || head == end) {
			return head;
		}
		Node* newHead = NULL;
		Node* newEnd = NULL;
		Node* pivot = partition(head, end, &newHead, &newEnd);
		if (newHead != pivot) {
			Node* tmp = newHead;
			while (tmp->next != pivot) {
				tmp = tmp->next;
			}
			tmp->next = NULL;
			newHead = quickSortRecur(newHead, tmp);
			tmp = getTail(newHead);
			tmp->next = pivot;
		}
		pivot->next = quickSortRecur(pivot->next, newEnd);
		return newHead;
	}
	
};

int main() {
	LinkedList list;
	list.insert(5);
	list.insert(4);
	list.insert(3);
	list.insert(2);
	list.insert(1);
	list.print();
	list.head = list.mergeSort(list.head);
	list.print();
	list.head = list.quickSortRecur(list.head, list.getTail(list.head));
	list.print();
	return 0;
}