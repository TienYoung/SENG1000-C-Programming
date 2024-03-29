/*
* FILE : m3.cpp
* PROJECT : SENG1000 - MAJOR ASSIGNMENT 3
* PROGRAMMER : Tian Yang, 8952896
* FIRST VERSION : 2024-02-15
* DESCRIPTION :
* This program calculate hotel bills for a meeting.
*/

#pragma warning(disable: 4996)

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define NAME_LENGTH 32

const int kError = -1;
const char* kWeekdays[] = { "sun", "mon", "tue", "wed", "thu", "fri", "sat" };

int indexTheDay(const char*);
double calculateCostOfRoom(const double[], int, int);

int main(void)
{
	const double kRoomRate[] = { 137.50, 138.25, 130.50, 150, 150, 162.50 };
	const int kCountOfPeople = 4;
	double total = 0.0;
	for (int i = 0; i < kCountOfPeople; i++)
	{
		char buffer[BUFFER_SIZE] = "";
		char name[NAME_LENGTH] = "";
		printf("Enter Name: ");
		fgets(buffer, BUFFER_SIZE, stdin);
		sscanf(buffer, "%[^\n]", name);
		if (name[0] == '\0')
		{
			printf("Invalid name entry. Moving on to next guest...\n");
			printf("\n");
			continue;
		}

		char checkInDay[4] = "";
		int checkIn = kError;
		printf("Enter check-in day: ");
		fgets(buffer, BUFFER_SIZE, stdin);
		sscanf(buffer, "%s\n", checkInDay);
		checkIn = indexTheDay(checkInDay);
		if (checkIn == kError)
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

		char checkOutDay[4] = "";
		int checkOut = kError;
		printf("Enter check-out day: ");
		fgets(buffer, BUFFER_SIZE, stdin);
		sscanf(buffer, "%s\n", checkOutDay);
		checkOut = indexTheDay(checkOutDay);
		if(checkOut == kError)
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

		double cost = calculateCostOfRoom(kRoomRate, checkIn, checkOut);
		printf("The total room cost for %s is %.2f\n", name, cost);
		printf("\n");
		total += cost;
	}
	printf("Grand total : %.2f", total);	

	return 0;
}

//
// FUNCTION : indexTheDay
// DESCRIPTION :
// This function converts from the user input to a useful array index
// PARAMETERS :
// const char* day : day string.
// RETURNS :
// int : index of day.
//
int indexTheDay(const char* day)
{
	for (int i = 0; i < 7; i++)
	{
		if (strcmp(day, kWeekdays[i]) == 0)
			return i;
	}
	return kError;
}

//
// FUNCTION : calculateCostOfRoom
// DESCRIPTION :
// This function calculates the cost of the room for a person.
// PARAMETERS :
// const double roomRate[] : room rate.
// int checkIn: check-in day.
// int checkOut: check-out day.
// RETURNS :
// double : total cost of the room.
//
double calculateCostOfRoom(const double roomRate[], int checkIn, int checkOut)
{
	double cost = 0.0;
	for (int i = checkIn; i < checkOut; i++)
	{
		cost += roomRate[i];
	}
	return cost;
}