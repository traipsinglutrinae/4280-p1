Project 1 option 3

This project uses an FSA table stored in scanner.h and uses the FSA driver stored in scanner.cpp.

The FSA table is minimalistic in nature([4][6]) and uses the same lookup technique to identify operator tokens that is used to identify keyword tokens. A much larger FSA table could have been used which included a final state for every operator token however if lookup was allowed for keywords after the fact it may as well be used for operators as well to simplify the table and driver.

To compile program run command: make
To run program run command: ./scanner <file>
	Where <file> is the target file to be scanned.
To clean up run command: make clean

Program accepts file name input with or without extension. 
	If extention isnt exactly ".sp2020" file is rejected as not found.
	If file does not have ".sp2020" extension it is rejected as not found.

Test files are located in testFiles/ sub directory.

