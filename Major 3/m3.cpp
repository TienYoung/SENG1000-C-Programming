/*
* Student ID: tyang2896
* FILE : m3.cpp
* PROJECT : SENG1000 - MAJOR ASSIGNMENT 3
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-02-15
* DESCRIPTION :
* This program calculate hotel bills for a meeting.
*/

#include <stdio.h>
#include <string.h>


const int k_error = - 1;
const char* k_weekdays[] = { "sun", "mon", "tue", "wed", "thu", "fri", "sat" };

int indexTheDay(const char*);
double calculateCostOfRoom(const double[], int, int);
int getNum(void);

int main(int argc, char* argv[])
{
	const double roomRate[] = { 137.5, 138.25, 130.5, 150, 150, 162.5 };
	const int countOfPeople = 4;
	for (int i = 0; i < countOfPeople; i++)
	{
		char* name = NULL;
		printf("Enter Name: ");
		if (!fgets(name, 32, stdin)) 
		{
			printf("Invalid name entry. Moving on to next guest...");
		}

		char* checkIn = NULL;
		printf("Enter check - in day : ");
		if (!fgets(checkIn, 3, stdin))
		{
			printf("Invalid check-in day. Moving on to next guest...");
		}

		char* checkOut = NULL;
		printf("Enter check - out day : ");
		if (!fgets(checkOut, 3, stdin))
		{
			printf("Invalid check-out day. Moving on to next guest...");
		}


		printf("\n");

			printf("Invalid name entry. Moving on to next guest...");
	}

	return 0;
}

int indexTheDay(const char* day)
{
	for (int i = 0; i < 7; i++)
	{
		if (day == k_weekdays[i])
			return i;
	}
	return k_error;
}

double calculateCostOfRoom(const double roomRate[], int in, int out)
{
	double cost = 0.0;
	for (int i = in; i < out; i++)
	{
		cost += roomRate[i];
	}
	return cost;
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