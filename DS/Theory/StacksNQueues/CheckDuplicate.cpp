#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Given a string s, remove duplicate letters so that every letter appears once and only once. 
// You must make sure your result is the smallest in lexicographical order among all possible results.

// using queues

string removeDuplicateLetters(string s) {
	int n = s.length();
	queue<char> q;
	int count[26] = { 0 };
	bool visited[26] = { false };
	for (int i = 0; i < n; i++) {
		cout << count[s[i] - 'a'];
		count[s[i] - 'a']++;
	}
	for (int i = 0; i < n; i++) {
		count[s[i] - 'a']--;
		if (visited[s[i] - 'a']) {
			continue;
		}
		while (!q.empty() && q.front() > s[i] && count[q.front() - 'a'] > 0) {
			visited[q.front() - 'a'] = false;
			q.pop();
		}
		q.push(s[i]);
		visited[s[i] - 'a'] = true;
	}
	string ans = "";
	while (!q.empty()) {
		ans += q.front();
		q.pop();
	}
	return ans;
}

int main() {
	string s = "bcabc";
	cout << removeDuplicateLetters(s);
	return 0;
}


	






