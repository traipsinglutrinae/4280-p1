/*Ian Lofton Green
 *CS428
 *Project 1
 *Option 3
*/

#include <iostream>
#include <istream>
#include "token.h"
#include "scanner.h"
#include "testScanner.h"

int relativeLineIndex;
int relativeIndex;
bool commentState = false;
string inputLine;

bool isValidChar(char input) {
	if(!isalpha(input) && !isdigit(input) && !isOp(input)) {
		return false;
	}
	else {
		return true;
	}
}

int sanitizer(string &rawInput) {
	char space = ' ';
	char currentChar;
	char nextChar;
	char pastChar;
	string sanitizedInput;
	
	//cout << "\nRaw input: " << rawInput << endl;   //DIAGNOSTIC OUTPUT
	
	if (relativeIndex >= rawInput.length()) {
		return 0;
	}
	for (int n = relativeIndex; n < rawInput.length(); n++) {
		currentChar = rawInput.at(n);
		if (n > 0) {
			pastChar = rawInput.at(n-1);
		}
		if (currentChar == commentChar) {
			sanitizedInput.push_back(space);
			commentState = !commentState;
		}
		else if (!commentState) {
			if (isspace(currentChar)) {
				if (!isspace(pastChar)) {
					sanitizedInput.push_back(currentChar);
				}
			}
			else if (!isValidChar(currentChar)) {
				cout << "Error: Character (" << (relativeIndex + 1) << ") on line (" << relativeLineIndex << ") is invalid." << endl;
				return -1;
			}
			else {
				sanitizedInput.push_back(currentChar);
			}
		}
		relativeIndex++;
	}
	inputLine.assign(sanitizedInput);
//	cout << "Valid string to be scanned: " << sanitizedInput << endl;   //DIAGNOSTIC OUTPUT
	return relativeIndex;
}

int testScanner(istream &stream) {
	Token token;
	buildKWMap();
	buildOpMap();
	relativeLineIndex = 1;
	while (getline(stream, inputLine)) {
		relativeIndex = 0;
		if (sanitizer(inputLine) == -1) {
			return 1;
		}
		tokenIndex = 0;
		if (inputLine.length() > 0) {
			while (scanner(inputLine, token) == 0) {
				display(token);
			}
		}
		relativeLineIndex++;
	}
	if (stream.eof()) {
		token.ID = EOFTk;
		token.description = "EOFTk";
		if (relativeLineIndex > 1) {
			token.lineNumber = relativeLineIndex - 1;
		}
		else {
			token.lineNumber = relativeLineIndex;
		}
		display(token);
	}
	return 0;
}
