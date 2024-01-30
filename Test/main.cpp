#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	//int num = 12;
	//int check = 10;

	//if ((num && check) == 22)
	//{
	//	printf("True\n");
	//}
	//else
	//{
	//	printf("false\n");
	//}
	//printf("%d\n", num && check);

	//char test[] = "Darryl";
	//printf("String is %s\n", test);
	//printf("Array size is %llu\n", sizeof(test));
	//printf("Type(char) size is %lld\n", sizeof(char));

	char* a = malloc(10);

	for (size_t i = 0; i <10; i++)
	{
		a[i] = 'a';
		printf("%c\n", a[i]);
	}


	return 0;
}