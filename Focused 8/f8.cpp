/*
 * FILE : f8.cpp
 * PROJECT : SENG1000 - FOCUSED ASSIGNMENT 8
 * PROGRAMMER : Tian Yang
 * FIRST VERSION : 2024-03-19
 * DESCRIPTION :
 * This program practice at working with C-style strings, files, command-line arguments, and structs.
 */

#pragma warning(disable: 4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGTH 41 // 20(directory) + 20(filename) + 1(terminator)

typedef struct 
{
    int howMany;
    const char* theText;
    const char* directoryPath;
    const char* filename;
} MyDat;

int main(int argc, char* argv[])
{
    if(argc != 5)
    {
        printf("Error: Incorrect number of arguments.\n");
        return 1;
    }
    MyDat myArgs = {
        strtol(argv[1], NULL, 10),
        argv[2],
        argv[3],
        argv[4]};
        
    char filename[MAXLENGTH] = "";
    strcpy(filename, myArgs.directoryPath);
    strcat(filename, "\\");
    FILE* file = fopen(strcat(filename, myArgs.filename), "w");
    if(file == NULL)
    {
        printf("Can't open or create %s\n", filename);
        return 0;
    }
    for (int i = 0; i < myArgs.howMany; i++)
    {
        if(fprintf(file, "%s\n", myArgs.theText) < 0)
        {
            printf("Can't write to %s\n", filename);
            break;
        }
    }
    if(fclose(file))
    {
        printf("Can't close %s\n", filename);
    }

    return 0;
}