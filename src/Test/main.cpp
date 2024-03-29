#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int TestOperator(void)
{
    int num = 12;
    int check = 10;

    if ((num && check) == 22)
    {
        printf("True\n");
    }
    else
    {
        printf("false\n");
    }
    printf("%d\n", num && check);

    return 0;
}

int TestMemory(void)
{
    char test[] = "Darryl";
    printf("String is %s\n", test);
    printf("Array size is %llu\n", sizeof(test));
    printf("Type(char) size is %lld\n", sizeof(char));

    char* a = malloc(10);

    for (size_t i = 0; i < 10; i++)
    {
        a[i] = 'a';
        printf("%c\n", a[i]);
    }

    return 0;
}

void swap(int A, int B);
void swapPtr(int* pA, int* pB);
#ifdef __cplusplus
void swapRef(int& rA, int& rB);
#endif
int TestSwap(void)
{


    int a = 10;
    int b = 20;

    swap(a, b);
    printf("A: %d B: %d\n", a, b);

    a = 10;
    b = 20;
    swapPtr(&a, &b);
    printf("Ptr A: %d Ptr B: %d\n", a, b);

#ifdef __cplusplus
    a = 10;
    b = 20;
    swapRef(a, b);
    printf("Ref A: %d Ref B: %d\n", a, b);
#endif

    return 0;
}
void swap(int A, int B)
{
    int temp = A;
    A = B;
    B = temp;
}

void swapPtr(int* pA, int* pB)
{
    int temp = *pA;
    *pA = *pB;
    *pB = temp;
}

#ifdef __cplusplus
void swapRef(int& rA, int& rB)
{
    int temp = rA;
    rA = rB;
    rB = temp;
}
#endif

int main(int argc, char* argv[])
{
#ifdef TEST_OPERATOR
    printf("Testing Opearator.......\n");
    printf("Result: %d\n", TestOperator());
#endif
#ifdef TEST_MEMORY
    printf("Testing Memory.......\n");
    printf("Result: %d\n", TestMemory());
#endif
#ifdef TEST_SWAP
    printf("Testing Swap.......\n");
    printf("Result: %d\n", TestSwap());
#endif
    FILE* file = fopen("test.txt", "w+");
    fputs("Hello\0World!", file);
    fclose(file);
    return 0;
}