#include <iostream>

using namespace std;

class HashTableEntry {
public:
	int k;
	int v;
	HashTableEntry* next;
	HashTableEntry(int k, int v) {
		this->k = k;
		this->v = v;
		this->next = NULL;
	}
};

class ContactBook {
private:
	HashTableEntry** t;
	int size;
public:
	ContactBook(int size) {
		this->size = size;
		t = new HashTableEntry * [this->size];
		for (int i = 0; i < size; i++)
			t[i] = NULL;
	}

	int HashFunc(int k) {
		return k % size;
	}

	void Insert(int k, int v) {
		int hash = HashFunc(k);
		HashTableEntry* entry = new HashTableEntry(k, v);
		if (t[hash] == NULL) {
			t[hash] = entry;
		}
		else {
			HashTableEntry* prev = NULL;
			HashTableEntry* curr = t[hash];
			while (curr != NULL && curr->k != k) {
				prev = curr;
				curr = curr->next;
			}
			if (curr == NULL) {
				prev->next = entry;
			}
			else {
				curr->v = v;
			}
		}
	}

	int SearchKey(int k) {
		int hash = HashFunc(k);
		if (t[hash] == NULL)
			return -1;
		else {
			HashTableEntry* curr = t[hash];
			while (curr != NULL && curr->k != k)
				curr = curr->next;
			if (curr == NULL)
				return -1;
			else
				return curr->v;
		}
	}

	void Delete(int k) {
		int hash = HashFunc(k);
		if (t[hash] != NULL) {
			HashTableEntry* prev = NULL;
			HashTableEntry* curr = t[hash];
			while (curr != NULL && curr->k != k) {
				prev = curr;
				curr = curr->next;
			}
			if (curr == NULL) {
				cout << "No element found at key " << k << endl;
				return;
			}
			if (prev == NULL) {
				t[hash] = t[hash]->next;
			}
			else {
				prev->next = curr->next;
			}
			delete curr;
			cout << "Element Deleted" << endl;
		}
	}

	void Display() {
		for (int i = 0; i < size; i++) {
			cout << i << ": ";
			HashTableEntry* entry = t[i];
			while (entry != NULL) {
				cout << entry->k << " " << entry->v << " --> ";
				entry = entry->next;
			}
			cout << endl;
		}
	}
};

int main() {
	
	ContactBook cb(7); // 1 % 7 = 1 ... 2 % 7 = 2
 	cb.Insert(1, 10);
	cb.Insert(2, 20);
	cb.Insert(42, 80);
	cb.Insert(9, 25);
	cb.Insert(12, 44);
	cb.Insert(14, 32);
	cb.Insert(17, 11);
	cb.Insert(13, 78);
	cb.Insert(37, 97);

	cb.Display();

	cout << "\nValue of the key 37 : " << cb.SearchKey(37) << endl;
	cout << "Value of the key 1 : " << cb.SearchKey(1) << endl;

	cb.DeleteKey(9);

	cout << "\nAfter deleting key 37\n" << endl;
	cb.Display();

	return 0;
}
	
