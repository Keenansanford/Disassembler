Disassembler Summary,

This code translates 32-bit machine language MIPS instructions into assembly language.

It was written in C using SublimeText Editor and compiled using Apple's XCode under the direction of Dr. Aylce Brady at Kalamazoo College. 

The classes are described in detail below:

binToDec - converts binary numbers into decimal format.

getRegName - if the MIPS instruction requires a register to do its job, this function provides the appropriate one using a table.

main - steps through the file line by line and reads the command or identifies when a command is invalid.

processIFormat - processes binary I format MIPS instructions. The input must be a valid I-format MIPS command.

processJFormat - processes binary J format MIPS instructions. The input must be a valid J-format MIPS command.

processRFormat - processes binary R format MIPS instructions. The input must be a valid R-format MIPS command.

testFile - contains lines of 32-bit commands to test the program.

verifyMIPSInstruction - verifies that the command is 32 letters long and that each of those is either a 0 or 1.
