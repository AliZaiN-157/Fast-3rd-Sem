// Convert a postfix expression to the corresponding fully-parenthesizedinfix expression.
// For example, a b + and a b + c d - *should produce(a + b) and ((a + b) * (c - d)), respectively.

#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x)
{
return (x >= 'a && x <= 'z') ||
		(x >= 'A' && x <= 'Z');
}

string getInfix(string exp)
{
	stack<string> s;

	for (int i=0; exp[i]!='\0'; i++)
	{
		if (isOperand(exp[i]))
		{
		string op(1, exp[i]);
		s.push(op);
		}

		else
		{
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();
			s.push("(" + op2 + exp[i] +
				op1 + ")");
		}
	}
	return s.top();
}

// Driver code
int main()
{
	string exp = "ab*c+";
	cout << getInfix(exp);
	
	string exp1 = "ab+cd-*";
	cout << getInfix(exp1);
	return 0;
}

