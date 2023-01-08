#include "HTMLChecker.h"


HTMLChecker::HTMLChecker() {
    self_closing_tags = {
            "<!doctype>", "<area>", "<base>", "<br>", "<col>", "<embed>", "<hr>",
            "<img>", "<input>", "<link>", "<meta>", "<param>", "<source>", "<track>", "<wbr>",
            "<!doctype/>", "<area/>", "<base/>", "<br/>", "<col/>", "<embed/>", "<hr/>",
            "<img/>", "<input/>", "<link/>", "<meta/>", "<param/>", "<source/>", "<track/>", "<wbr/>"
    };
}



/**
 * Takes the path of a html file and loads it into a
 * Queue one word at a time.  The method reads in the file
 * one character at a time, using a state machine with 4
 * states to parse the tags and words into a Queue for later
 * evaluation.
 *
 * @param file_path
 * @return true if the file could be read.
 */
bool HTMLChecker::load(const string &file_path) {
    // open the file and make sure there is something in it.
    fstream file_in(file_path, fstream::in);
    bool is_empty = file_in.peek() == std::ifstream::traits_type::eof();
    if (is_empty) return false;

    string buff = "";            // holds the word or tag string as we build it.
    char character;              // holds the char we read from the file
    State state = whitespace;    // set our initial state to whitespace

    // loop though each char in the file
    while (file_in >> noskipws >> character) {

        if (state == whitespace) {
            if (!isspace(character)) {
                // if you find a < is the start of a tag
                // otherwise its the start of a word
                if (character == '<') state = tag;
                else state = word;
                buff = character;
            }
        } else if (state == tag) {
            // if it's a > we've reached the end of the tag
            if (character == '>') {
                buff += '>';
                state = whitespace;
                // add the tag to the heml elements queue
                html_elements.push(buff);
                buff = "";

            } else if (isspace(character)) {
                // space in the tag means we're looking at attributes
                state = tag_attr;
            } else {
                buff += tolower(character);
            }
        } else if (state == tag_attr) {
            // in the tag attributes ignore everything but the >
            if (character == '>') {
                buff += '>';
                html_elements.push(buff);
                buff = "";
                state = whitespace;
            }
        } else if (state == word) {
            if (isspace(character)) {
                html_elements.push(buff);
                buff = "";
                state = whitespace;
            } else if (character == '<') {
                html_elements.push(buff);
                buff = "";
                state = tag;
                buff += character;
            } else {
                buff += character;
            }
        }
    }
    return true;
}

// In this assignment you only need to write the isValid method, the HTMLCheker::isValid(). In this method
// you will read from std::queue and std::unordered_set and push and pop from a std::stack. You will also need
// to use the std::string::find method to find the closing tag in the unordered_set.  You will need to use
// the std::string::substr method to get the tag name from the string.  You will need to use the std::string::compare
// method to compare the tag name to the tag name in the unordered_set.

//bool HTMLChecker::isValid() {
//	stack<string> tags;
//	while (!html_elements.empty()) {
//		string element = html_elements.front();
//		html_elements.pop();
//		if (element[0] == '<') {
//			if (element[1] == '/') {
//				if (tags.empty()) return false;
//				string tag = tags.top();
//				tags.pop();
//				string tag_name = element.substr(2, element.length() - 3);
//				if (tag.compare(tag_name) != 0) return false;
//			}
//			else {
//				if (self_closing_tags.find(element) == self_closing_tags.end()) {
//					tags.push(element);
//				}
//			}
//		}
//	}
//	return tags.empty();
//}


bool HTMLChecker::isValid() {
	
	// Create a stack to hold the tags
	stack<string> tagStack;

	// Loop through the queue
	while (!html_elements.empty()) {

		// Get the next element from the queue
		string element = html_elements.front();

		// If the element is a tag
		if (element[0] == '<') {

			// If the tag is a self-closing tag, ignore it
			if (self_closing_tags.find(element) != self_closing_tags.end()) {
				html_elements.pop();
				continue;
			}

			// If the tag is a closing tag
			if (element[1] == '/') {

				// If the stack is empty, the html is invalid
				if (tagStack.empty()) {
					return false;
				}

				// Get the top element from the stack
				string top = tagStack.top();

				// If the top element is not the same as the closing tag, the html is invalid
				if (top != element.substr(2, element.length() - 3)) {
					return false;
				}

				// Pop the top element from the stack
				tagStack.pop();
			}

			// If the tag is an opening tag
			else {

				// Push the tag onto the stack
				tagStack.push(element.substr(1, element.length() - 2));
			}
		}

		// Pop the element from the queue
		html_elements.pop();
	}

	// If the stack is empty, the html is valid
	if (tagStack.empty()) {
		return true;
	}

	// Otherwise, the html is invalid
	return false;
}




