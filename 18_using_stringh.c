#include <stdio.h>
#include <string.h>

int main()
{
    char str1[20] = "hi";
    char str2[20] = "hello every1";

    /* 1. strcpy */
    strcpy(str1, str2);
    printf("str1 : %s\n", str1);

    /* 2. strcmp */
    if (!strcmp(str1, str2)) printf("%s and %s is equal\n", str1, str2);
    else printf("%s and %s are not equal\n", str1, str2);
}