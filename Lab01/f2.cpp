/*
* FILE : f2.cpp
* PROJECT : SENG1000 - FOCUSED ASSIGNMENT 1
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-01-17
* DESCRIPTION :
* The functions in this file are used to calculate the sum from 1 to 500.
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int sum = 0;
    for (int i = 1; i <= 500; ++i)
    {
        sum += i;
    }
    printf("%d\n", sum);
    
    return 0;
}