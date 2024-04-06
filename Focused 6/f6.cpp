/*
 * FILE : f6.cpp
 * PROJECT : SENG1000 - FOCUSED ASSIGNMENT 6
 * PROGRAMMER : Tian Yang
 * FIRST VERSION : 2024-03-08
 * DESCRIPTION :
 * This program uses pointer variables to modify parameters.
 */

#pragma warning(disable: 4996)

#include <stdio.h>

#define NUMBER_LENGTH 7

int getDouble(double *pNumber);
void doubleTheData(double *d1, double *d2, double *d3, double *d4);
void calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage);
void fillArray(double values[], int numArray, double fillValue);

int main()
{
	// Four numbers.
	double d1 = 0.0;
	double d2 = 0.0;
	double d3 = 0.0;
	double d4 = 0.0;
	double *pd1 = &d1;
	double *pd2 = &d2;
	double *pd3 = &d3;
	double *pd4 = &d4;
	printf("Enter 4 floating-point number, one number per input line\n");
	printf("Enter a number: ");
	if (getDouble(pd1) == 0)
		return 0;
	printf("Enter a number: ");
	if (getDouble(pd2) == 0)
		return 0;
	printf("Enter a number: ");
	if (getDouble(pd3) == 0)
		return 0;
	printf("Enter a number: ");
	if (getDouble(pd4) == 0)
		return 0;

	double average = 0.0;
	double sum = 0.0;

	// Double.
	doubleTheData(pd1, pd2, pd3, pd4);
	printf("After doubling the numbers the new values are: %.2lf, %.2lf, %.2lf, %.2lf\n", d1, d2, d3, d4);

	// Seven numbers.
	double numbers[NUMBER_LENGTH] = {0.0};
	printf("Enter 7 floating-point number, one number per input line\n");
	for (int i = 0; i < NUMBER_LENGTH; i++)
	{
		printf("Enter a number: ");
		if (getDouble(&numbers[i]) == 0)
			return 0;
	}

	// Average and sum.
	calculateArrayStats(numbers, NUMBER_LENGTH, &sum, &average);
	printf("The average and sum of the array elements: %lf, %lf\n", average, sum);

	// Fill.
	fillArray(numbers, NUMBER_LENGTH, 40.0);
	printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf\n", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6]);

	return 0;
}

/*
Function: getDouble()
Parameter: double *pNumber: pointer to a variable that is filled in by the
user input, if valid.
Return Value: int: 1 if the user entered a valid floating-point number, 0 otherwise
Description: This function gets a floating-point number from the user. If the user
enters a valid floating-point number, the value is put into the variable pointed to
by the parameter and 1 is returned. If the user-entered value is not valid, 0 is returned.
*/
int getDouble(double *pNumber)
{
	/* we will see in a later lecture how we can improve this code */
	char record[121] = {0}; /* record stores the string */
	/* NOTE to student: indent and brace this function consistent with
	your others */
	/* use fgets() to get a string from the keyboard */
	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	 * corresponding with the number of items it found in the string */
	if (sscanf(record, "%lf", pNumber) != 1)
	{
		return 0;
	}

	return 1;
}

/*
Function: doubleTheData()
Parameters: double *d1, *d2, *d3, *d4: four pointers to floating-point numbers.
Description: This function takes pointers to four floating-point numbers passed
as doubles and double them all.
Return value: none
*/
void doubleTheData(double *d1, double *d2, double *d3, double *d4)
{
	*d1 *= 2;
	*d2 *= 2;
	*d3 *= 2;
	*d4 *= 2;
}

/*
Function: calculateArrayStats()
Parameters: double values[]: floating-point numbers

int numArray: number of array elements

double *pSum: pointer to a variable that is filled in by this function with the
sum of all elements in the array

double *pAverage: pointer to a variable that is filled in by this function with
the average of all elements in the array

Return Value: none
Description: This function takes an array of floating-point(double) numbers,
given the number of elements in the array as a parameter, and calculates the
average and sum of the numbers. Once calculated, the average gets put into the
variable pointed to by the pAverage parameter and the sum gets put into the
variable pointed to by the pSum parameter.
*/
void calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage)
{
	*pSum = 0.0;
	for (int i = 0; i < numArray; i++)
	{
		*pSum += values[i];
	}
	*pAverage = *pSum / numArray;
}

/*
Function: fillArray()
Parameters: double values[]: floating-point numbers
int numArray: number of array elements
double fillValue: value to put into array elements
Return Value: none
Description: This function takes an array of floating-point(double) numbers,
given the number of elements in the array as a parameter, and puts the fillValue
into each element of the array.
*/
void fillArray(double values[], int numArray, double fillValue)
{
	for (int i = 0; i < numArray; i++)
	{
		values[i] = fillValue;
	}
}