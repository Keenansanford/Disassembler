// I wrote this class myself based of a template provided by the college.
#ifndef	main_h
#define	main_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Define types and declare global variables used throughout program. */
// (none)

/* Declare functions used within program. */
int binToDec(char string[], int begin, int end);
int verifyMIPSInstruction(int lineNum, char string[]);
char * processRFormat(char string[]);
char * processIFormat(char string[]);
char * processJFormat(char string[]);

#endif
