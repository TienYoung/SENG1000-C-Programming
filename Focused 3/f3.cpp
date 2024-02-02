#include <stdio.h>
#include <stdbool.h>

int getNum(void);
bool isGreaterThan(int);

int main(int argc, char* argv[])
{
	printf("Please input number: ");
	int num = getNum();
	printf("Get: %d\n", num);
	return 0;
}

#pragma warning(disable: 4996) // required by Visual Studio
int getNum(void)
{
	/* the array is 121 bytes in size; we'll see in a later lecture how we can
	improve this code */
	char record[121] = { 0 }; /* record stores the string */
	int number = 0;
	/* NOTE to student: brace this function consistent with your others */
	/* use fgets() to get a string from the keyboard */
	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	* corresponding with the number of items it found in the string */
	if (sscanf(record, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		* the system, set number to -1 */
		number = -1;
	}
	return number;
}

bool isGreaterThan(int num)
{
	return num > 1000;
}