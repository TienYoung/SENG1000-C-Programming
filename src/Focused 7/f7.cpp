/*
 * FILE : f7.cpp
 * PROJECT : SENG1000 - FOCUSED ASSIGNMENT 7
 * PROGRAMMER : Tian Yang
 * FIRST VERSION : 2024-03-18
 * DESCRIPTION :
 * This program practice at creating text and binary files.
 */

#include <stdio.h>

int main()
{
	FILE* myTextFile = fopen("myTextFile.txt", "w");
	fprintf(myTextFile, "This is line 1.\nThis is line 2.\n");
	fclose(myTextFile);

	FILE* myEvenDataList = fopen("myEvenDataList.data", "wb");
	const unsigned short kBinaryData[] = {26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308};
	fwrite(kBinaryData, sizeof(unsigned short), sizeof(kBinaryData) / sizeof(unsigned short), myEvenDataList);
	fclose(myEvenDataList);

	return 0;
}
