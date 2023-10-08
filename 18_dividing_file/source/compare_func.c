char compare(char *str1, char *str2)
{
    while (*str1)
    {
        if (*str1 != *str2) return 1;
        str1++;
        str2++;
    }

    if (*str2) return 1;
    else return 0;
}