#include <iostream>

using namespace std;

// Question:
//The program that you are tasked with resembles the website "Stack Overflow" where any user posts up a question 
//regarding a problem in their technological domain and experienced programmers respond to those questions by 
// answering them.Your job is to let any user post up a question and let the commenters post replies.

// Devise a technique using data structures that implements this kind of applicationand stores the posts as well 
// as the answers to the question in an appropriate Data Structure technique.

class HashTable {
private:
	int tableSize;

	class Post {
	public:
		string question;
		string answer;
		Post* next;
	};

	Post** StackOverflow;
public:
	HashTable(int tableSize);
	int Hash(string key);
	void AddQuestion(string question);
	void AddAnswer(string answer);
	void PrintQuestions();
	void PrintAnswers();
};

HashTable::HashTable(int tableSize) {
	this->tableSize = tableSize;
	StackOverflow = new Post * [tableSize];
	for (int i = 0; i < tableSize; i++) {
		StackOverflow[i] = new Post;
		StackOverflow[i]->question = "empty";
		StackOverflow[i]->answer = "empty";
		StackOverflow[i]->next = NULL;
	}
}

int HashTable::Hash(string key) {
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++) {
		hash = hash + (int)key[i];
	}

	index = hash % tableSize;

	return index;
}

void HashTable::AddQuestion(string question) {
	int index = Hash(question);

	if (StackOverflow[index]->question == "empty") {
		StackOverflow[index]->question = question;
	}
	else {
		Post* Ptr = StackOverflow[index];
		Post* n = new Post;
		n->question = question;
		n->next = NULL;
		while (Ptr->next != NULL) {
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

void HashTable::AddAnswer(string answer) {
	int index = Hash(answer);

	if (StackOverflow[index]->answer == "empty") {
		StackOverflow[index]->answer = answer;
	}
	else {
		Post* Ptr = StackOverflow[index];
		Post* n = new Post;
		n->answer = answer;
		n->next = NULL;
		while (Ptr->next != NULL) {
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

void HashTable::PrintQuestions() {
	int number = 0;
	for (int i = 0; i < tableSize; i++) {
		Post* Ptr = StackOverflow[i];
		if (Ptr->question != "empty") {
			cout << "Question " << number << endl;
			cout << Ptr->question << endl;
			while (Ptr->next != NULL) {
				Ptr = Ptr->next;
				cout << Ptr->question << endl;
			}
		}
		number++;
	}
}

void HashTable::PrintAnswers() {
	int number = 0;
	for (int i = 0; i < tableSize; i++) {
		Post* Ptr = StackOverflow[i];
		if (Ptr->answer != "empty") {
			cout << "Answer " << number << endl;
			cout << Ptr->answer << endl;
			while (Ptr->next != NULL) {
				Ptr = Ptr->next;
				cout << Ptr->answer << endl;
			}
		}
		number++;
	}
}

int main() {
	HashTable StackOverflow(10);

	StackOverflow.AddQuestion("How do I create a hash table?");
	StackOverflow.AddAnswer("You create a hash table by using a hash function to map keys to values.");
	
	StackOverflow.AddQuestion("How do I create a linked list?");
	StackOverflow.AddAnswer("You create a linked list by using pointers to link nodes together.");

	StackOverflow.AddQuestion("How do I create a binary search tree?");
	StackOverflow.AddAnswer("You create a binary search tree by using pointers to link nodes together.");

	StackOverflow.AddQuestion("How do I create a stack?");
	StackOverflow.AddAnswer("You create a stack by using pointers to link nodes together.");

	StackOverflow.AddQuestion("How do I create a hash table?");
	StackOverflow.AddAnswer("You create a hash table by using a hash function to map keys to values.");

	cout << "Questions: " << endl;
	StackOverflow.PrintQuestions();
	cout << endl;
	
	cout << "Answers: " << endl;
	StackOverflow.PrintAnswers();


	return 0;
}



