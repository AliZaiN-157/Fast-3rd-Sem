#include <iostream>

using namespace std;

// Transfer data from 2D matrix to Hashtable

class HashTableEntry {
public:
	int key;
	int value;

	HashTableEntry(int key, int value) {
		this->key = key;
		this->value = value;
	}
};

class HashMapTable {
private:
	HashTableEntry** table;
	int size;
public:
	HashMapTable(int size) {
		this->size = size;
		table = new HashTableEntry * [size];
		for (int i = 0; i < size; i++) {
			table[i] = NULL;
		}
	}

	int HashFunc(int key) {
		return key % size;
	}

	void Insert(int key, int value) {
		int hash = HashFunc(key);
		while (table[hash] != NULL && table[hash]->key != key) {
			hash = HashFunc(hash + 1);
		}
		if (table[hash] != NULL)
			delete table[hash];
		table[hash] = new HashTableEntry(key, value);
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			if (table[i] != NULL)
				cout << table[i]->key << " " << table[i]->value << endl;
			else
				cout << "NULL" << endl;
		}
	}
};

int main() {
	
	int matrix[][2] = { {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6} };
	
	HashMapTable a(5);
	
	for (int i = 0; i < 5; i++) {
		a.Insert(matrix[i][0], matrix[i][1]);
	}

	a.print();

	// Given a 2d array arr[][] with each row representing a pair representing entry and exit time of a car in a parking lot, 
	// the task is to calculate the maximum number of cars that can be parked at the same time.
	// using hashing

	int cars[][2] = { {1120, 1159}, { 1508, 1529 }, { 1508, 1527 }, { 1503, 1600 }, { 1458, 1629 }, { 1224, 1313 } };

	HashMapTable b(5);
	
	for (int i = 0; i < 6; i++) {
		b.Insert(cars[i][0], cars[i][1]);
	}

	b.print();
	
}


	