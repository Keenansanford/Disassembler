/*
 * processRFormat
 *
 * This function processes binary machine code for R format instructions.
 * 
 * 		char * processRFormat (char string[]);
 *			Pre-condition: machine instruction passed via string is R format.
 *			Post-condition: returns assembly language string associated with
 *							machine code.
 *			Returns: the correspinding I-Format instruction.
 *			Output: prints the corresponding I-format instruction.
 *
 * Implementation:
 *      "instr" must be a valid, 32-bit MIPS instruction.
 *
 *	Author: Keenan Sanford 4/20/2015
 *
 */

#include "processRFormat.h"

char * processRFormat (char string[])
	// Returns the assembly language string associated with the 32 byte command.
{
	static char returnString[BUFSIZ];
	char * destReg = getRegName(binToDec(string, 6, 10));
	char * srcReg1 = getRegName(binToDec(string, 11, 15));
	char * srcReg2 = getRegName(binToDec(string, 16, 20));
	int shftAmnt = binToDec(string, 21, 25);
	int functCode = binToDec(string, 26, 31);

	if ( functCode == 0 )
	{
		sprintf(returnString, "sll %s, %s, %d \n", srcReg1, srcReg2, shftAmnt);
	}

	else if ( functCode == 2 )
	{
		sprintf(returnString, "sll %s, %s, %d \n", srcReg1, srcReg2, shftAmnt);
	}

	else if ( functCode == 8 )
	{
		sprintf(returnString, "jr %s \n", srcReg1);
	}

	else if ( functCode == 32 )
	{
		sprintf(returnString, "add %s, %s, %s \n", destReg, srcReg1, srcReg2);
	}

	else if ( functCode == 33 )
	{
		sprintf(returnString, "addu %s, %s, %s \n", destReg, srcReg1, srcReg2);
	}

	else if ( functCode == 34 )
	{
		sprintf(returnString, "sub %s, %s, %s \n", destReg, srcReg1, srcReg2);
	}

	else if ( functCode == 35 )
	{
		sprintf(returnString, "subu %s, %s, %s \n", destReg, srcReg1, srcReg2);
	}

	else if ( functCode == 36 )
	{
		sprintf(returnString, "and %s, %s, %s \n", destReg, srcReg1, srcReg2);
	}

	else if ( functCode == 37 )
	{
		sprintf(returnString, "or %s, %s, %s \n", destReg, srcReg1, srcReg2);
	}

	else if ( functCode == 39 )
	{
		sprintf(returnString, "nor %s, %s, %s \n", destReg, srcReg1, srcReg2);
	}

	else if ( functCode == 42 )
	{
		sprintf(returnString, "slt %s, %s, %s \n", destReg, srcReg1, srcReg2);
	}

	else if ( functCode == 43 )
	{
		sprintf(returnString, "sltu %s, %s, %s \n", destReg, srcReg1, srcReg2);
	}

	else
	{
		sprintf(returnString, "Unrecognizable functcode.\n");
	}

	return returnString;
}
