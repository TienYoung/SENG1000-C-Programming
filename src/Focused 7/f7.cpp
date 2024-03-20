/*
 * FILE : f7.cpp
 * PROJECT : SENG1000 - FOCUSED ASSIGNMENT 7
 * PROGRAMMER : Tian Yang
 * FIRST VERSION : 2024-03-18
 * DESCRIPTION :
 * This program practice at creating text and binary files.
 */
#include <stdio.h>

int main(void)
{
	FILE* myTextFile = fopen("myTextFile.txt", "w");
	if (myTextFile == NULL)
	{
		printf("Can't open or create myTextFile.txt");
	}
	else
	{
		if (fprintf(myTextFile, "This is line 1.\nThis is line 2.\n") < 0)
		{
			printf("Can't write to myTextFile.txt");
		}
		else
		{
			if (fclose(myTextFile) != 0)
			{
				printf("Can't close myTextFile.txt");
			}
		}
	}

	FILE* myEvenDataList = fopen("myEvenDataList.data", "wb");
	if (myEvenDataList == NULL)
	{
		printf("Can't open or create myEvenDataList.data");
	}
	else
	{
		const unsigned short kBinaryData[] = {
			26946, 24942, // Bina
			31090, 25632, // ry d
			29793, 8289,  // ata
			28518, 8306,  // for
			28537, 33141, // you
			39308};
		size_t count = sizeof(kBinaryData) / sizeof(unsigned short);
		if (fwrite(kBinaryData, sizeof(unsigned short), count, myEvenDataList) < count)
		{
			printf("Can't write to myEvenDataList.data");
		}
		else
		{
			if (fclose(myEvenDataList) != 0)
			{
				printf("Can't close myEvenDataList.data");
			}
		}
	}

	return 0;
}
