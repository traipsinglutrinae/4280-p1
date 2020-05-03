/*Ian Lofton Green
 *CS428
 *Project 1
 *Option 3
*/

#include <string>
#include <cstring>
#include <iostream>
#include "scanner.h"
#include "token.h"

using namespace std;

void scannerError(int error, string input) {
	if (error == errorNum) {
		cout << "Error: Tokens may not begin with a number. Number error occured on line (" << relativeLineIndex << ") at position (" << relativeIndex << ")." << endl;
	}
	else {
		cout << "Error: An unidentified error has occured.\nNo further information is available" << endl;
	}
}

int getCol(char input) {
	if (isalpha(input)) {
		return 0;
	}
	else if (isdigit(input)) {
		return 2;
	}
	else if (isOp(input)) {
		return 3;
	}
	else if (isspace(input)) {
		return 4;
	}
	else {
		cout << "Error: Failed to match input character (" << input << ") to FSA table column." << endl;
		return -1;
	}
}

int tokenIndex;
int scanner(string &inputString, Token &token) {
	token.lineNumber = relativeLineIndex;
	string newDescription;
	const char space = ' ';
	char nextChar;
	char lastChar;
	int nextInput;
	int currentState = 0;
	int nextState;
	while (tokenIndex <= inputString.length()) {
		if (tokenIndex < inputString.length()) {
			lastChar = nextChar;
			nextChar = inputString.at(tokenIndex);
		}
		else {
			nextChar = space;
		}
		nextInput = getCol(nextChar);
		nextState = FSATable[currentState][nextInput];
		if (nextState > 10) {
			token.description = newDescription;
			//cout << "\n" + nextState << endl;   /DIAGNOSTIC OUTPUT
			if (nextState == IDFinState) {
				if (isKW(token) != -1) {
					token.ID = keyTk;
					token.description. append(" >  Description: < " + newDescription);
				}
				else {
					token.ID = IDTk;
					token.description.assign("IDTk >  Description: < " + newDescription);
				}
			}
			else if (nextState == IntFinState) {
				token.ID = intTk;
				token.description.assign("IntTk >  Description: < " + newDescription);
			}
			else if (nextState == OpFinState) {
				if ((nextChar == '=') && (lastChar == '=')) {   //is ==
					token.ID = opTk;
					token.description.assign("==");
					getOp(token);
					token.description.append(" > Description: < ==");
					tokenIndex++;   //skip next char
				}
				else {   //is just =
					token.ID = opTk;
					getOp(token);
					token.description.append(" >  Description: < " + newDescription);
				}
			}
			else {
				cout << "Error: Final state match could not be made." << endl;
				return -1;
			}
			return 0;
		}
		else if (nextState < 0) {
			currentState = 0;
			scannerError(nextState, inputString);
			tokenIndex++;
			return -1;
		}
		currentState = nextState;
		tokenIndex++;
		if (!isspace(nextChar)) {
			newDescription.push_back(nextChar);
		}
	}
	return -1;
}

