/*
* FILE : f2.cpp
* PROJECT : SENG1000 - FOCUSED ASSIGNMENT 1
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-01-17
* DESCRIPTION :
* Show the result of sum from 1 to 500.
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int sum = 0;
    int from = 1;
    const int to = 500;
    while (from <= to)
    {
        sum += from;
        ++from;
    }
    printf("%d\n", sum);
    
    return 0;
}