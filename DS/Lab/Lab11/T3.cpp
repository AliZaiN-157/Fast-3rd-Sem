#include <iostream>
#include <stdlib.h>

using namespace std;

class HashTableEntry {
public:
	int k;
	int v;
	HashTableEntry(int k, int v) {
		this->k = k;
		this->v = v;
	}

};

class ContactBook {
private:
	HashTableEntry** t;
	int size;
public:
	ContactBook(int size) {
		this->size = size;
		t = new HashTableEntry* [this->size];
		for (int i = 0; i < size; i++)
			t[i] = NULL;
		
	}

	int HashFunc(int k) {
		return k % size;
	}

	void Insert(int k, int v) {
		int hash = HashFunc(k);
		while (t[hash] != NULL && t[hash]->k != k)
			hash = HashFunc(hash + 1);
		if (t[hash] != NULL)
			delete t[hash];
		t[hash] = new HashTableEntry(k, v);
	}

	int SearchKey(int k) {
		int hash = HashFunc(k);
		while (t[hash] != NULL && t[hash]->k != k)
			hash = HashFunc(hash + 1);
		if (t[hash] == NULL)
			return -1;
		else
			return t[hash]->v;
	}

	void Remove(int k) {
		int hash = HashFunc(k);
		while (t[hash] != NULL) {
			if (t[hash]->k == k)
				break;
			hash = HashFunc(hash + 1);
		}
		if (t[hash] == NULL) {
			cout << "No Element found at key " << k << endl;
			return;
		}
		else {
			delete t[hash];
		}
		cout << "Element Deleted" << endl;
	}

	~ContactBook() {
		for (int i = 0; i < size; i++)
			if (t[i] != NULL)
				delete t[i];
		delete[] t;
	}
	
};

int main() {
	ContactBook cb(10);
	int k, v;
	int choice;
	while (true) {
		cout << "1.Insert element into the table" << endl;
		cout << "2.Search element from the key " << endl;
		cout << "3.Delete element at a key" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter element to be inserted: ";
			cin >> v;
			cout << "Enter key at which element to be inserted: ";
			cin >> k;
			cb.Insert(k, v);
			break;
		case 2:
			cout << "Enter key of the element to be searched: ";
			cin >> k;
			if (cb.SearchKey(k) == -1) {
				cout << "No element found at key " << k << endl;
				continue;
			}
			else {
				cout << "Element at key " << k << " : ";
				cout << cb.SearchKey(k) << endl;
			}
			break;
		case 3:
			cout << "Enter key of the element to be deleted: ";
			cin >> k;
			cb.Remove(k);
			break;
		case 4:
			exit(1);
		default:
			cout << "\nEnter correct option " << endl;
		}
	}
	return 0;
}
