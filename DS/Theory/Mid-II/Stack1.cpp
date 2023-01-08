#include <iostream>
#include <string>

using namespace std;

// The Stack class
class Stack
{
private:
	char* stackArray; // Pointer to the stack array
	int stackSize;    // The stack size
	int top;          // Indicates the top of the stack
	
public:
	// Constructor
	Stack(int) {
		stackArray = new char[stackSize];
		top = -1;
	}

	// Copy constructor
	Stack(const Stack& obj) {
		
			// Copy the stack size
			stackSize = obj.stackSize;

			// Create the stack array
			stackArray = new char[stackSize];

			// Copy the stack contents
			for (int count = 0; count < stackSize; count++)
				stackArray[count] = obj.stackArray[count];

			// Set the top of the stack
			top = obj.top;
		}
	

	// Destructor
	~Stack() {
		delete[] stackArray;
	}

	// Stack operations
	void push(char num)
	{
		if (isFull())
			cout << "The stack is full.\n";
		else
		{
			top++;
			stackArray[top] = num;
		}
	}
	void pop(char& num)
	{
		if (isEmpty())
			cout << "The stack is empty.\n";
		else
		{
			num = stackArray[top];
			top--;
		}
	}
	bool isFull() const
	{
		bool status;

		if (top == stackSize - 1)
			status = true;
		else
			status = false;

		return status;
	}
	bool isEmpty() const
	{
		bool status;

		if (top == -1)
			status = true;
		else
			status = false;

		return status;
	}
};


// Create a Stack that reads a string and exactly one character at the time and determines whether the string contains 
// balanced parentheses; that is for every left parentheses (if it exists) there is another right matching parentheses.

int main()
{
	// Create a Stack object
	Stack stack(100);

	// Create a string
	string str;

	// Get the string
	cout << "Enter a string: ";
	getline(cin, str);

	// Create a char variable
	char ch;

	// Create a bool variable
	bool balanced = true;

	// Create a for loop
	for (int i = 0; i < str.length(); i++)
	{
		// Get the char
		ch = str[i];

		// If the char is a left parentheses
		if (ch == '(')
		{
			// Push the char
			stack.push(ch);
		}
		// If the char is a right parentheses
		else if (ch == ')')
		{
			// Pop the char
			stack.pop(ch);

			// If the stack is empty
			if (stack.isEmpty())
			{
				// Set balanced to false
				balanced = false;
			}
		}
	}

	// If the stack is not empty
	if (!stack.isEmpty())
	{
		// Set balanced to false
		balanced = false;
	}

	// If balanced is true
	if (balanced)
	{
		// Display a message
		cout << "The string is balanced.\n";
	}
	// If balanced is false
	else
	{
		// Display a message
		cout << "The string is not balanced.\n";
	}

	return 0;
}