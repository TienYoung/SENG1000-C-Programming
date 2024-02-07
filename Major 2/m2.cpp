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

int getNum(void);
int powerCalculation(int, int);
int numberRangeChecker(int, int, int);

int main(int argc, char* argv[])
{
	int num = 0;
	const int exitNum = 4;
	int base = 1;
	int exponent = 1;
	while (num != exitNum)
	{
		/*
		* Prompt use to enter number.
		*/
		printf("\n");
		printf("\n");
		printf("Menu: \n");
		printf("\t1. Change base \n");
		printf("\t2. Change exponent \n");
		printf("\t3. Display base raised to exponent\n");
		printf("\t4. Exit program\n");
		printf("Option? ");
		num = getNum();

		if (num == 1)
		{
			printf("Enter new base: ");
			int newBase = getNum();
			if (numberRangeChecker(newBase, 1, 30))
			{
				base = newBase;
			}
			else
			{
				printf("Invalid base. Please enter a number between 1 and 30.\n");
			}
		}
		else if (num == 2)
		{
			printf("Enter new exponent: ");
			int newExponent = getNum();
			if (numberRangeChecker(newExponent, 1, 6))
			{
				exponent = newExponent;
			}
			else
			{
				printf("Invalid base. Please enter a number between 1 and 6.\n");
			}
		}
		else if (num == 3)
		{

			printf("%d raised to the power of %d is %d\n", base, exponent, powerCalculation(base, exponent));
		}
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
int powerCalculation(int base, int exponent)
{
	int result = 1;
	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return result;
}

int numberRangeChecker(int value, int min, int max)
{
	return ((value <= max) && (value >= min)) ? 1 : 0;
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