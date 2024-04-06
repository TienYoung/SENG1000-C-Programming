/*
* FILE : m4.cpp
* PROJECT : SENG1000 - MAJOR ASSIGNMENT 4
* PROGRAMMER : Tian Yang, 8952896
* FIRST VERSION : 2024-03-19
* DESCRIPTION :
* This program to display flight information where the least fare found for given
* source – destination pair.
*/

#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS 41
#define MAX_FLIGHTS 100

// Error Code
#define S_OK 0
#define S_MISSINGDASH 1
#define S_MISSINCOMMA 2
#define S_MISSFILE 3

typedef struct
{
    char airline[MAX_CHARS];
    char source[MAX_CHARS];
    char destination[MAX_CHARS];
    int fare;
} Flight;

int processFlight(const char*, Flight[], int*);
void displayLeastFareDetails(const Flight[], int);
int parseLine(char*, char*, int*, char*);

int main(void)
{
    Flight flights[MAX_FLIGHTS] = {};
    int flights_count = 0;
    
    FILE* flightsTXT = fopen("flights.txt", "r");
    if(flightsTXT == NULL)
    {
        printf("flights.txt not exist!\n");
        return 0;
    }
    char line[MAX_CHARS] = "";
    while(fgets(line, MAX_CHARS, flightsTXT) != NULL)
    {
        char filename[MAX_CHARS] = "";
        sscanf_s(line, "%[^\n]", filename, MAX_CHARS);
        int count = 0;
        int result = processFlight(filename, &flights[flights_count], &count);
        if(result == S_MISSFILE)
        {
            printf("Error: %s not exist!\n", filename);
        }
        flights_count += count;

    }
    displayLeastFareDetails(flights, flights_count);


    return 0;
}

//
// FUNCTION : processFlight
// DESCRIPTION :
// This function process airline file.
// PARAMETERS :
// const char* filename : airline filename
// Flight flights[] : array of struct of flight data
// int* count : count of array
// RETURNS :
// int : error code
//
int processFlight(const char* filename,  Flight flights[], int* count)
{
    FILE* airlineTXT = fopen(filename, "r");
    if(airlineTXT == NULL)
    {
        return S_MISSFILE;
    }

    char line[MAX_CHARS];
    int i = 0;
    while(fgets(line, MAX_CHARS, airlineTXT) != NULL)
    {
        char source[MAX_CHARS] = "";
        char destination[MAX_CHARS] = "";
        int fare = 0;
        int result = parseLine(source, destination, &fare, line);
        switch (result)
        {
        case S_OK:
            sscanf_s(filename, "%[^.]", flights[i].airline, MAX_CHARS);
            strcpy(flights[i].source, source);
            strcpy(flights[i].destination, destination);
            flights[i].fare = fare;
            ++i;
            break;
        case S_MISSINCOMMA:
            printf("Error: Miss comma\n");
        case S_MISSINGDASH:
            printf("Error: Miss dash\n");
        default:
            break;
        }
        
    }
    *count = i;

    fclose(airlineTXT);
    
    return S_OK;
}

//
// FUNCTION : displayLeastFareDetails
// DESCRIPTION :
// This function display the least fare details in all flights
// PARAMETERS :
// Flight flights[] : array of struct of flight data
// int* count : count of array
// RETURNS :
// void
//
void displayLeastFareDetails(const Flight flights[], int count)
{
    const Flight* cheapestFlights[MAX_FLIGHTS] = {NULL};
    int cheapestCount = 0;

    for(int i = 0; i < count; ++i)
    {
        const Flight* flightA = &flights[i];
        bool found = false;
        for(int j = i + 1; j < count; ++j)
        {
            const Flight* flightB = &flights[j];
            if((strcmp(flightA->source, flightB->source) == 0) && (strcmp(flightA->destination, flightB->destination) == 0))
            {
                if( flightA->fare < flightB -> fare)
                {
                    cheapestFlights[cheapestCount++] = flightA;
                }
                found = true;
            }
        }
        if(found == false)
        {
            cheapestFlights[cheapestCount++] = flightA;
        }
    }

    for(int i = 0; i < cheapestCount; ++i)
    {
        printf("%s : %s to %s, fare $%d\n", cheapestFlights[i]->airline, cheapestFlights[i]->source, cheapestFlights[i]->destination, cheapestFlights[i]->fare);
    }
}

//
// FUNCTION : parseLine
// DESCRIPTION :
// This function parse the line in airline file
// PARAMETERS :
// char* source : source
// char* destination : destination
// int* fare : fare
// char* line: line data from airline file
// RETURNS :
// int: error code
//
int parseLine(char* source, char* destination, int* fare, char* line)
{
    int index = sscanf_s(line, "%[a-zA-Z] - %[a-zA-Z], %d\n", source, MAX_CHARS, destination, MAX_CHARS, fare);
    if(index == 1)
    {
        return S_MISSINGDASH;
    }
    if (index == 2)
    {
        return S_MISSINCOMMA;
    }
    
    return S_OK;
}