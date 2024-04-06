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
    const char* textFilename = "myTextFile.txt";
    FILE* myTextFile = fopen(textFilename, "w");
    if (myTextFile == NULL)
    {
        printf("Can't open or create %s\n", textFilename);
    }
    else
    {
        if (fprintf(myTextFile, "This is line 1.\nThis is line 2.\n") < 0)
        {
            printf("Can't write to %s\n", textFilename);
        }
        else
        {
            if (fclose(myTextFile) != 0)
            {
                printf("Can't close %s\n", textFilename);
            }
        }
    }

    const char* binFilename = "myEvenDataList.data";
    FILE* myEvenDataList = fopen(binFilename, "wb");
    if (myEvenDataList == NULL)
    {
        printf("Can't open or create %s\n", binFilename);
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
        for (int i = 0; i < count; i++)
        {
            if (kBinaryData[i] % 2 == 0) // This is even number.
            {
                if (fwrite(&kBinaryData[i], sizeof(unsigned short), 1, myEvenDataList) < 1)
                {
                    printf("Can't write to %s\n", binFilename);
                    break;
                }
            }
        }
        if (fclose(myEvenDataList) != 0)
        {
            printf("Can't close %s\n", binFilename);
        }
    }

    return 0;
}
