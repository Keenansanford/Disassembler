/*
 * binToDec
 *
 * This function converts the binary digits from string[begin] to
 * string[end] to a decimal integer.
 *
 * int binToDec(char string[], int begin, int end)
 *   Pre-condition:  begin and end are valid indices in array string;
 *   		     every character from string[begin] to string[end]
 *		     (including those two) has a character value '0' or '1'
 *   Returns: the decimal equivalent of the binary number represented by
 *	      the characters in string[begin] - string[end].
 *            (If begin > end, this function arbitrarily returns 0.)
 *
 * For example, assume A is a character array that contains the
 *    following characters:
 *            '1'  '0'  '1'  '1'  '0'  '1'  '0'  '0'  '1'
 *    The call binToDec(A, 2, 5) converts the binary number 1101
 *    (represented by the substring A[2] - A[5]) to the decimal integer
 *    13 and returns it.
 * 
 * Note: The decimal value returned may appear to be negative if the
 * string being converted is long enough (end - begin + 1 == 32)
 * and if the first character is '1'.
 *
 * Author: Alyce Brady
 * With assistance from: Keenan Sanford
 *
 * Creation Date:	idk
 * Modified:	4/10/2015		Didn't work at all.
 *
 */
#include <stdio.h>
#include <math.h>

// The documentation and frame for this class was provided by Kalamazoo college. I filled in the class allowing it to work as intended.
int binToDec(char string[], int begin, int end)
{
	int i;
	int j;
	int decimal = 0;
	int powOf2 = 1;
	int curIndex;

	for ( i = end; i >= begin; i-- ) {
		curIndex = string[i] - '0';
		if ( curIndex == 1 ) {
			decimal += powOf2;
		}

		powOf2 *= 2;
	}

	return decimal;
}
