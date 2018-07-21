#include "int_seq_array.h"

#include <stdio.h>

int main(int argc, char const *argv[])
{
    array test;
    type value = 0;

    printf("array testing started...\n");
    if(FAILED == initialize(&test, 2, 4, 5))
    {
        printf("initialize array failed.\n");
        return -1;
    }

    printf("initialize array with 2 dimensionalities(4, 5) success.\n");
    if(FAILED == assign(&test, 10, 3, 4))
    {
        printf("assign value 10 for array failed.\n");
        return -1;
    }

    printf("assign value 10 for array success.\n");
    if(FAILED == assign(&test, 11, 1, 4))
    {
        printf("assign value 11 for array failed.\n");
        return -1;
    }

    printf("assign value 11 for array success.\n");
    if(FAILED == value_of(test, &value, 3, 4))
    {
        printf("get value at postion[3,4] of array failed.\n");
        return -1;
    }

    printf("get value at position[3,4] of array success, value is [%d]\n", value);
    if(FAILED == destroy(&test))
    {
        printf("destroy array failed.\n");
        return -1;
    }

    printf("destroy array success.\n");
    printf("array testing finished...\n");
    return 0;
}
