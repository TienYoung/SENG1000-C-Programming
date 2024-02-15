/*
* FILE : m2.cpp
* PROJECT : SENG1000 - Major ASSIGNMENT 2
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-02-09
* DESCRIPTION :
* This program calculates powers using a function that I create.
*/

#include <stdio.h>
#include <stdbool.h>

int getNum(void);
int powerCalculation(int, int);
int numberRangeChecker(int, int, int);

int main(int argc, char* argv[])
{
	int num = 0;
	int base = 1;
	int exponent = 1;
	bool exit = false;
	while (!exit)
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
		else if (num == 4)
		{
			exit = true;
		}
		else
		{
			printf("Invalid entry\n");
		}
	}

	return 0;
}

//
// FUNCTION : powerCalculation
// DESCRIPTION :
// This function calculate power.
// PARAMETERS :
// int base : base.
// int exponent: exponent.
// RETURNS :
// int : result of power.
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

//
// FUNCTION : numberRangeChecker
// DESCRIPTION :
// This function check if a number is in the range.
// PARAMETERS :
// int value : number be checked.
// int min : minimum.
// int max : maximum.
// RETURNS :
// int : 1 is in the range, 0 is out of range.
//
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