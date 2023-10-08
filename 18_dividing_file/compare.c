#include "main.h"

char compare(char *str1, char *str2)
{
    int i = 0;
    while (str1[i])
    {
        if (str1[i] != str2[i]) return 1;
        i++;
    }

    if (str2[i]) return 1;
    else return 0;
}