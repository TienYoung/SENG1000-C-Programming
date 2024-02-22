/*
* Student Number: 8952896
* FILE : m3.cpp
* PROJECT : SENG1000 - MAJOR ASSIGNMENT 3
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-02-15
* DESCRIPTION :
* This program calculate hotel bills for a meeting.
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define BUFFER_SIZE 1024
#define NAME_LENGTH 32

const int k_error = -1;
const char* k_weekdays[] = { "sun", "mon", "tue", "wed", "thu", "fri", "sat" };

int indexTheDay(const char*);
double calculateCostOfRoom(const double[], int, int);
int getNum(void);

int main(int argc, char* argv[])
{
	const double roomRate[] = { 137.5, 138.25, 130.5, 150, 150, 162.5 };
	const int countOfPeople = 4;
	double total = 0.0;
	for (int i = 0; i < countOfPeople; i++)
	{
		char buffer[BUFFER_SIZE] = { 0 };
		char name[NAME_LENGTH] = { 0 };
		printf("Enter Name: ");
		assert(fgets(buffer, sizeof(buffer), stdin) != NULL);
		assert(sscanf_s(buffer, "%[^\n]", name, NAME_LENGTH) != EOF);
		if (*name == '\0')
		{
			printf("Invalid name entry. Moving on to next guest...\n");
			printf("\n");
			continue;
		}

		char checkInDay[4] = { 0 };
		int checkIn = k_error;
		printf("Enter check-in day: ");
		assert(fgets(buffer, sizeof(buffer), stdin) != NULL);
		assert(sscanf_s(buffer, "%s\n", checkInDay, sizeof(checkInDay)) != EOF);
		checkIn = indexTheDay(checkInDay);
		if (checkIn == k_error)
		{
			printf("Invalid check-in day. Moving on to next guest...\n");
			printf("\n");
			continue;
		}
		if ((checkIn > 4)) // Index of Thursday.
		{
			printf("This person is missing the meeting. Moving on to next guest...\n");
			printf("\n");
			continue;
		}

		char checkOutDay[4] = { 0 };
		int checkOut = k_error;
		printf("Enter check-out day: ");
		assert(fgets(buffer, sizeof(buffer), stdin) != NULL);
		assert(sscanf_s(buffer, "%s\n", checkOutDay, sizeof(checkOutDay)) != EOF);
		checkOut = indexTheDay(checkOutDay);
		if(checkOut == k_error)
		{
			printf("Invalid check-out day. Moving on to next guest...\n");
			printf("\n");
			continue;
		}
		if (checkOut < 4) // Index of Thursday.
		{
			printf("This person is missing the meeting. Moving on to next guest...\n");
			printf("\n");
			continue;
		}
		

		if ((checkOut - checkIn) < 1)
		{
			printf("Invalid length of stay. Moving on to next guest...\n");
			printf("\n");
			continue;
		}

		double cost = calculateCostOfRoom(roomRate, checkIn, checkOut);
		printf("The total room cost for %s is %.2f\n", name, cost);
		printf("\n");
		total += cost;
	}
	printf("Grand total : %.2f", total);	

	return 0;
}

int indexTheDay(const char* day)
{
	for (int i = 0; i < 7; i++)
	{
		if (strcmp(day, k_weekdays[i]) == 0)
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