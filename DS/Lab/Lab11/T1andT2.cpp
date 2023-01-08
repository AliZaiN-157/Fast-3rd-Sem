#include <iostream>

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

const int TABLE_SIZE = 10;

class HashMapTable {
private:
	HashTableEntry** t;
public:
	HashMapTable() {
		t = new HashTableEntry* [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++) {
			t[i] = NULL;
		}
	}

	int division_Hash(int k) {
		return k % TABLE_SIZE;
	}

	// multiplication hash function using floor function
	int multiplication_Hash(int k) {
		float A = 0.6180339887;
		float val = k * A;
		val = val - floor(val);
		return floor(TABLE_SIZE * val);
	}

	// universal hash function
	int universal_Hash(int k) {
		int a = 31415, b = 27183;
		return ((a * k + b) % 32768) % TABLE_SIZE;
	}

	// folding hash function
	int folding_Hash(int k) {
		int key = k;
		int sum = 0;
		while (key > 0) {
			sum += key % 10;
			key = key / 10;
		}
		return sum % TABLE_SIZE;
	}

	// mid-square hash function
	int midSquare_Hash(int k) {
		int key = k * k;
		int sum = 0;
		while (key > 0) {
			sum += key % 10;
			key = key / 10;
		}
		return sum % TABLE_SIZE;
	}

	// radix hash function of base 16
	int radix_Hash(int k) {
		int key = k;
		int sum = 0;
		while (key > 0) {
			sum += key % 16;
			key = key / 16;
		}
		return sum % TABLE_SIZE;
	}

	void Insert(int k, int v) {
		int hash = division_Hash(k);
		while (t[hash] != NULL && t[hash]->k != k) {
			hash = division_Hash(hash + 1);
		}
		if (t[hash] != NULL)
			delete t[hash];
		t[hash] = new HashTableEntry(k, v);
	}

	int SearchKey(int k) {
		int hash = division_Hash(k);
		while (t[hash] != NULL && t[hash]->k != k) {
			hash = division_Hash(hash + 1);
		}
		if (t[hash] == NULL)
			return -1;
		else
			return t[hash]->v;
	}

	void Remove(int k) {
		int hash = division_Hash(k);
		while (t[hash] != NULL) {
			if (t[hash]->k == k)
				break;
			hash = division_Hash(hash + 1);
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

	
	
	~HashMapTable() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (t[i] != NULL)
				delete t[i];
			delete[] t;
		}
	}
};

int main() {
	HashMapTable hash;
	int k, v;
	int c;
	while (1) {
		cout << "1.Insert element into the table" << endl;
		cout << "2.Search element from the key" << endl;
		cout << "3.Delete element at a key" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> c;
		switch (c) {
		case 1:
			cout << "Enter element to be inserted: ";
			cin >> v;
			cout << "Enter key at which element to be inserted: ";
			cin >> k;
			hash.Insert(k, v);
			break;
		case 2:
			cout << "Enter key of the element to be searched: ";
			cin >> k;
			if (hash.SearchKey(k) == -1) {
				cout << "No element found at key " << k << endl;
				continue;
			}
			else {
				cout << "Element at key " << k << " : ";
				cout << hash.SearchKey(k) << endl;
			}
			break;
		case 3:
			cout << "Enter key of the element to be deleted: ";
			cin >> k;
			hash.Remove(k);
			break;
		case 4:
			exit(1);
		default:
			cout << "\nEnter correct option\n";
		}
	}
	return 0;
}