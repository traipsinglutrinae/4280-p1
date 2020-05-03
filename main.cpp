/*Ian Lofton Green
 *CS428
 *Project 1
 *Option 3
*/

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "token.h"
#include "scanner.h"
#include "testScanner.h"

using namespace std;

int main(int argc, char* argv[]) {
	ifstream inFile;
	char * inFileName;
	
	if (argc > 2) {
		cout << "##########################################################################" << endl;
		cout << "Error: Too many arguments. Correct invocation: scanner <target file name>" << endl;
		cout << "##########################################################################" << endl;
		return -1;
	}
	else if (argc < 2) {
		cout << "##########################################################################" << endl;
		cout << "Error: Too few arguments. Correct invocation: scanner <target file name>" << endl;
		cout << "##########################################################################" << endl;
		return -1;
	}
	else if (argc == 2) {
		string fileName = argv[1];
		if ((fileName[fileName.length() - 1] != '0') && (fileName[fileName.length() - 2] != '2') && (fileName[fileName.length() - 3] != '0') && (fileName[fileName.length() - 4] != '2') && (fileName[fileName.length() - 5] != 'p') && (fileName[fileName.length() - 6] != 's') && (fileName[fileName.length() - 7] != '.'))  {
			fileName.append(".sp2020");
		} //This isnt falwless
		inFileName = new char[fileName.length() + 1];
		strcpy(inFileName, fileName.c_str());
		inFile.open(inFileName, ifstream::in);
		if (inFile.is_open()) {
			cout << inFileName << " opened successfully!" << endl;
			testScanner(inFile);
		}
		else {	
			cout << "Error: File could not be opened, please verify file name and extension if applicable." << endl;
			return -1;
		}
	}
	inFile.close();
	return 0;
}
			
