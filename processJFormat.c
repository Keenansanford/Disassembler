/*
 * processJFormat
 *
 * This function processes binary machine code for J format instructions.
 * 
 *		char * processRFormat (char string[]);
 *			Pre-condition: machine instruction passed via string is J format.
 *			Post-condition: returns assembly language string associated with
 *							machine code.
 *			Returns: the correspinding J-Format instruction.
 *			Output: prints the corresponding J-format instruction.
 *
 * Implementation:
 *      "instr" must be a valid, 32-bit MIPS instruction.
 *
 *	Author: Keenan Sanford 4/20/2015
 *
 */

#include "processJFormat.h"

// I wrote this portion of the code myself.
char * processJFormat (char string[])
	// Returns the assembly language string associated with the 32 byte command.
{
	static char returnString[BUFSIZ];
	int opCode = binToDec(string, 0, 5);
	int address = binToDec(string, 6, 31);

	if ( opCode == 2 )
	{
		sprintf(returnString, "j %d \n", address);
	}

	else
	{
		sprintf(returnString, "jal %d \n", address);
	}

	return returnString;
}
