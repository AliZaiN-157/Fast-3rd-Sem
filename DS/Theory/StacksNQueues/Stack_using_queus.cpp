#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Create stack using queues (using two queues)

class Stack {
	int N;
	queue<int> q1, q2;
public:
	Stack() {
		N = 0;
	}
	void push(int x) {
		q2.push(x);
		N++;
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}
		queue<int> temp = q1;
		q1 = q2;
		q2 = temp;
	}
	void pop() {
		q1.pop();
		N--;
	}
	int top() {
		return q1.front();
	}
	int size() {
		return N;
	}
	bool empty() {
		return N == 0;
	}
};

// Create queues using stacks (using two stacks)

class Queue {
	int N;
	stack<int> s1, s2;
public:
	Queue() {
		N = 0;
	}
	void push(int x) {
		s1.push(x);
		N++;
	}
	void pop() {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		s2.pop();
		N--;
	}
	int front() {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}
	int size() {
		return N;
	}
	bool empty() {
		return N == 0;
	}
};


