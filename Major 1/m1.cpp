/*
* FILE : m1.cpp
* PROJECT : SENG1000 - MAJOR ASSIGNMENT 1
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-01-19
* DESCRIPTION :
* Print alphabet and the average of running total.
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
	int total = 0;
	int count = 0;
	const char kInitial = 'y';
	for (int i = 'a'; i <= 'z'; ++i)
	{
		++count;
		total += i;
		if (i == kInitial)
		{
			printf("%c\t%d\n", i, total / count);
		}
		else 
		{
			printf("%c\t%c\n", i, total / count);
		}
	}

	return 0;
}