/*
* FILE : f5.cpp
* PROJECT : SENG1000 - FOCUSED ASSIGNMENT 5
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-02-21
* DESCRIPTION :
* This program get integers from the user and determines which is the highest value.
*/

#include <stdio.h>
#include <limits.h>

#define ARRAY_LENGTH 10 // Define a macro as the number of loops and array length.

void modifyArrayValues(int[], int);
int maxArrayValue(int[], int);
int getNum(void);

int main(int argc, char* argv[])
{
	int numArray[ARRAY_LENGTH] = { 0 };
	modifyArrayValues(numArray, ARRAY_LENGTH);
	int index = maxArrayValue(numArray, ARRAY_LENGTH);
	printf("The highest value is %d at index %d", numArray[index], index);

	return 0;
}

//
// FUNCTION : modifyArrayValues
// DESCRIPTION :
// This function prompts the user to enter numbers and store them in an array.
// PARAMETERS :
// int[] : array for numbers.
// int : length of the array.
// RETURNS :
// void : nothing to return.
//
void modifyArrayValues(int array[], int length)
{
	printf("Please enter %d integers, pressing ENTER after each one:\n", length);
	for (int i = 0; i < length; i++)
	{
		array[i] = getNum();
	}
}

//
// FUNCTION : maxArrayValue
// DESCRIPTION :
// This function finds the highest value in an array.
// PARAMETERS :
// int[] : array for numbers.
// int : length of the array.
// RETURNS :
// int : index of the max number.
//
int maxArrayValue(int array[], int length)
{
	int index = 0;
	for (int i = 1; i < length; i++)
	{
		if (array[i] > array[index])
		{
			index = i;
		}
	}
	return index;
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