/*
 * FILE : f8.cpp
 * PROJECT : SENG1000 - FOCUSED ASSIGNMENT 8
 * PROGRAMMER : Tian Yang
 * FIRST VERSION : 2024-03-19
 * DESCRIPTION :
 * This program practice at working with C-style strings, files, command-line arguments, and structs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int howMany;
	const char* theText;
	const char* directoryPath;
	const char* filename;
} MyDat;

int main(int argc, char* argv[])
{
	MyDat myArgs = {strtol(argv[1], NULL, 10), argv[2], argv[3], argv[4]};
	char filename[40] = "";
	strcpy(filename, myArgs.directoryPath);
	FILE* file = fopen(strcat(filename, myArgs.filename), "w");
	for (int i = 0; i < myArgs.howMany; i++)
	{
		fprintf(file, "%s\n", myArgs.theText);
	}
	fclose(file);

	return 0;
}