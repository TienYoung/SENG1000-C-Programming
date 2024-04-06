/*
* FILE : f3.cpp
* PROJECT : SENG1000 - FOCUSED ASSIGNMENT 3
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-02-01
* DESCRIPTION :
* This program calls a function to get a number from the user and displays whether the
* number is greater than or less than or equal to 1000.
*/

#include <stdio.h>
#include <stdbool.h>

int getNum(void);
bool isGreaterThan(int);

int main(int argc, char* argv[])
{
	printf("Please enter a number: ");
	int num = getNum();

	if (isGreaterThan(num))
	{
		printf("%d is greater than 1000.\n", num);
	}
	else
	{
		printf("%d is less than or equal 1000.\n", num);
	}

	return 0;
}

//
// FUNCTION : isGreaterThan
// DESCRIPTION :
// This function compares a number with 1000.
// PARAMETERS :
// int num : this num is compared with 1000.
// RETURNS :
// bool : if is num greater than 1000.
//
bool isGreaterThan(int num)
{
	return num > 1000; // Check if the input number is greater than 1000.
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
#pragma warning(disable: 4996) // required by Visual Studio
int getNum(void)
{
	/* the array is 121 bytes in size; we'll see in a later lecture how we can
	improve this code */
	char record[121] = { 0 }; /* record stores the string */
	int number = 0;
	/* NOTE to student: brace this function consistent with your others */
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