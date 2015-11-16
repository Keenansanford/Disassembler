/*
 * Test Driver to test verifyMIPSInstruction and binToDec.
 *
 * This program reads lines from a file.  For each line, the program
 *      calls verifyMIPSInstruction.  If the line contains characters
 *      representing a valid MIPS instruction, the program calls
 *      binToDec for various segments of the instruction to test the
 *      binToDec function.
 *
 * Input:
 *      The program reads its input from a file passed in as a parameter
 *      on the command line, or reads from the standard input. The file should
 *      contain valid 32-bit machine language instructions
 *
 *              Check for valid machine language input
 *              Check for correct OP code
 *
 * Output:
 *      For each valid line, the program prints the corresponding MIPS
 *      instruction.
 *
 *              Check for correct format addressing.
 *              Check for correct register return.
 *
 *      For each invalid line, the program prints an error message to
 *      stderr saying so.  (The program also prints an error message if
 *      it cannot open the file.)
 *
 * Author: Alyce Brady
 *        with assistance from: Keenan Sanford
 *
 * Creation Date:  Creation_Date       4/20/2015
 *        modified: 4/20/2015          Didn't work as desired
 *
 */

#include "main.h"

// The reader portion of this file was fully functional prior to the project. The reader was updated to take a file input. It was further optimized to check the opcode and send the instruction to the appropriate MIPS format reader.
int main(int argc, char *argv[])
{
    char buffer[BUFSIZ];                  /* contains binary code */
    char mipsstr[BUFSIZ];                  /* contains translated MIPS */
    FILE * fptr;                          /* file pointer */
    int lineNum = 0;
    int length;

    /* Was a file passed in a parameter (e.g., on the command line)? */
    if ( argc == 2 )
    {
        /* Open the file for reading */
        if ((fptr = fopen (argv[1], "r")) == NULL)
        {
            fprintf (stderr, "Error: Cannot open file %s.\n", argv[1]);
            return 1;
        }
    }
    else  /* No file passed in; use standard input. */
        fptr = stdin;

    /* Continuously read next line of input until EOF is encountered.
     * Each line should contain a valid MIPS instruction and newline.
     */
    while (fgets (buffer, BUFSIZ, fptr))   /* fgets returns NULL if EOF */
    {
        lineNum++;

        /* If the last character in the string is a newline, "remove" it
         * by replacing it with a null byte.
         */
        length = strlen(buffer);
        if (buffer[length - 1] == '\n')
        {
            buffer[length - 1] = '\0';      /* convert newline to null byte */
        }

        /* Verify that the string contains 32 '0' and '1' characters.  If
         * it does, convert the binary code into MIPS and print the assembly
         * language equivalent of the binary code.
         */
        if ( verifyMIPSInstruction(lineNum, buffer) )
        {
            int opCode = binToDec(buffer, 0, 5);

            printf("opcode = %d \n", opCode);

            // What type of instruction does the binary represent? R, I, or J?
            if ( opCode == 0 )
            {
                sprintf(mipsstr, "R-Format MIPS on line number %d for %s: %s",
                                    lineNum, buffer, processRFormat(buffer));
            }

            else if ( opCode == 4 || opCode == 5 || opCode == 8 || opCode == 9 ||
                      opCode == 10 || opCode == 11 || opCode == 12 || opCode == 13 ||
                      opCode == 15 || opCode == 35 || opCode == 43 )
            {
                sprintf(mipsstr, "I-Format MIPS on line number %d for %s: %s",
                                    lineNum, buffer, processIFormat(buffer));
            }

            else if ( opCode == 2 || opCode == 3 )
            {
                sprintf(mipsstr, "J-Format MIPS on line number %d for %s: %s",
                                    lineNum, buffer, processJFormat(buffer));
            }


            else
            {
                printf("Unrecognizable opcode on line %d. \n", lineNum);
            }

            printf("%s", mipsstr);
        }
    }

    /* End-of-file encountered; close the file. */
    fclose (fptr);
    return 0;
}
