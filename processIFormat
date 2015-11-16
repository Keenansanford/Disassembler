/*
 * processIFormat
 *
 * This function processes binary machine code for I format instructions
 * 
 *		char * processRFormat (char string[]);
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

 #include "processIFormat.h"

char * processIFormat (char string[])
	// Returns the assembly language string associated with the 32 byte command.
{
	static char returnString[BUFSIZ];
	int opCode = binToDec(string, 0, 5);
	char * destReg = getRegName(binToDec(string, 6, 10));
	char * srcReg = getRegName(binToDec(string, 11, 15));
	int address = binToDec(string, 16, 31);

	if ( opCode == 4 )
	{
		sprintf(returnString, "beq %s, %s, %d \n", destReg, srcReg, address);
	}

	else if ( opCode == 5 )
	{
		sprintf(returnString, "bne %s, %s, %d \n", destReg, srcReg, address);
	}

	else if ( opCode == 8 )
	{
		sprintf(returnString, "addi %s, %s, %d \n", destReg, srcReg, address);
	}

	else if ( opCode == 9 )
	{
		sprintf(returnString, "addiu %s, %s, %d \n", destReg, srcReg, address);
	}

	else if ( opCode == 10 )
	{
		sprintf(returnString, "slti %s, %s, %d \n", destReg, srcReg, address);
	}

	else if ( opCode == 11 )
	{
		sprintf(returnString, "sltiu %s, %s, %d \n", destReg, srcReg, address);
	}

	else if ( opCode == 12 )
	{
		sprintf(returnString, "andi %s, %s, %d \n", destReg, srcReg, address);
	}

	else if ( opCode == 13 )
	{
		sprintf(returnString, "ori %s, %s, %d \n", destReg, srcReg, address);
	}

	else if ( opCode == 15 )
	{
		sprintf(returnString, "lui %s, %d \n", srcReg, address);
	}

	else if ( opCode == 35 )
	{
		sprintf(returnString, "lw %s, %s, %d \n", destReg, srcReg, address);
	}

	else
	{
		sprintf(returnString, "sw %s, %s, %d \n", destReg, srcReg, address);
	}

	return returnString;
}
