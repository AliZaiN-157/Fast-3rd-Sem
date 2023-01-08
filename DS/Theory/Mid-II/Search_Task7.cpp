#include <iostream>

using namespace std;

class SelfOrganizingList {
private:
	int* list;
	int size;
public:
	SelfOrganizingList(int size) {
		this->size = size;
		list = new int[size];
	}
	~SelfOrganizingList() {
		delete[] list;
	}
	
	void add(int index, int value) {
		list[index] = value;
	}
	
	int linearSearch(int item) {
		for (int i = 0; i < size; i++) {
			if (list[i] == item) {
				return i;
			}
		}
		return -1;
	}

	int binarySearch(int item) {
		int low = 0;
		int high = size - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (list[mid] == item) {
				return mid;
			}
			else if (list[mid] < item) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return -1;
	}
	// This function should move the item at the given index to the front of the list
	void moveToFront(int index) {
		int temp = list[index];
		for (int i = index; i > 0; i--) {
			list[i] = list[i - 1];
		}
		list[0] = temp;
	}
};

int main() {
	SelfOrganizingList list(10);
	for (int i = 0; i < 10; i++) {
		list.add(i, i);
	}
	cout << list.linearSearch(5) << endl;
	cout << list.binarySearch(5) << endl;
	list.moveToFront(5);
	cout << list.linearSearch(5) << endl;
	cout << list.binarySearch(5) << endl;
	return 0;
}