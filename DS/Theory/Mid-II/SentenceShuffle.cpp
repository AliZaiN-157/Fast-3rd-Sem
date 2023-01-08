#include <iostream>

using namespace std;


string sortSentence(string s);

int main()
{
	string s = "is2 sentence4 This1 a3";
	cout << "Original Sentence: " << s << endl;
	cout << "Sorted Sentence: " << sortSentence(s) << endl;
	return 0;
}

string sortSentence(string s)
{
	string result = "";
	string word = "";
	int index = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int n = s.length();
	int count = 0;
	int wordCount = 0;
	int wordIndex = 0;
	int wordLength = 0;
	int wordIndexArray[9] = { 0 };
	string wordArray[9] = { "" };

	// count the number of words in the sentence
	for (i = 0; i < n; i++)
	{
		if (s[i] == ' ')
		{
			count++;
		}
	}

	// add 1 to count to account for the last word
	count++;

	// loop through the sentence
	for (i = 0; i < n; i++)
	{
		// if the character is a space
		if (s[i] == ' ')
		{
			// get the index of the word
			index = s[i - 1] - '0';

			// store the word in the word array
			wordArray[index - 1] = word;

			// store the index of the word in the word index array
			wordIndexArray[index - 1] = index;

			// reset the word
			word = "";
		}
		// if the character is not a space
		else
		{
			// add the character to the word
			word += s[i];
		}
	}

	// get the index of the last word
	index = s[n - 1] - '0';

	// store the last word in the word array
	wordArray[index - 1] = word;

	// store the index of the last word in the word index array
	wordIndexArray[index - 1] = index;

	// loop through the word array
	for (i = 0; i < count; i++)
	{
		// get the length of the word
		wordLength = wordArray[i].length();

		// loop through the word
		for (j = 0; j < wordLength-1; j++)
		{
			// add the character to the result
			result += wordArray[i][j];
		}

		// add a space to the result
		result += " ";
	}
	
	// remove the last space from the result
	result.pop_back();
	
	// return the result
	return result;
}


