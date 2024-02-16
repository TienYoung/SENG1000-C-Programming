/*
* FILE : f4.cpp
* PROJECT : SENG1000 - FOCUSED ASSIGNMENT 4
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-02-14
* DESCRIPTION :
* This program get integers from the user and determines which is the highest value.
*/

#include <stdio.h>
#include <limits.h>

#define ARRAY_LENGTH 10 // Define a macro as the number of loops and array length.

int getNum(void);

int main(int argc, char* argv[])
{
	printf("Please enter 10 integers, pressing ENTER after each one:\n");
	int numArray[ARRAY_LENGTH] = { 0 };
	int max = INT_MIN; // make sure the max is minimum at initialization.
	int index = 0;
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		numArray[i] = getNum();

		if (numArray[i] > max)
		{
			/*
			* Record the maximum number and which's index so far.
			*/
			max = numArray[i];
			index = i; 
		}
	}
	printf("The highest value is %d at index %d", max, index);

	return 0;
}

//
// FUNCTION : getNum
// DESCRIPTION :
// This function gets user-entered number.
// PARAMETERS :
// void : nothing input.
// RETURNS :
// int : return the number that user entered.
//
#pragma warning(disable: 4996)
int getNum(void)
{
	/* we will see in a later lecture how we can improve this code */
	char record[121] = { 0 }; /* record stores the string */
	int number = 0;
	/* NOTE to student: indent and brace this function consistent with
	your others */
	/* use fgets() to get a string from the keyboard */
	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	* corresponding with the number of items it found in the string */
	if (sscanf(record, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		* the system, set number to -1 */
		number = -1;
	}
	return number;
}