/*Ian Lofton Green
 *CS428
 *Project 1
 *Option 3
*/

#ifndef SCANNER_H
#define SCANNER_H
#include "token.h"

using namespace std;

const int state0 = 0;
const int state1 = 1;
const int state2 = 2;
const int state3 = 3;
const int IDFinState = 11;
const int IntFinState = 12;
const int OpFinState = 13;
const int EOFFinState = 14;
const int errorNum = -1;
const int errorUpper = -1;
const int col = 6;
const int row = 4;
const int FSATable[row][col] = {
	{state2, state2, state3, state1, state0, EOFFinState},
	{OpFinState, OpFinState, OpFinState, OpFinState, OpFinState, OpFinState},
	{state2, state2, state2, IDFinState, IDFinState, IDFinState},
	{errorNum, errorNum, state3, IntFinState, IntFinState, IntFinState}
};

void scannerError(int, string);
int getCol(char);
int scanner(string &, Token &);

#endif
