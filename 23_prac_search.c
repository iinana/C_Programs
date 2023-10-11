#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Correct Usage : [program] [searching word]");
        exit(1);
    }

    FILE *fp = fopen("a.txt", "r");
    if (fp == NULL)
    {
        printf("File Reading Error");
        exit(1);
    }

    char c;
    int i, count = 0;
    while ((c = fgetc(fp)) != EOF)
    {
        i = 0;
        while ((c == argv[1][i]) && (argv[1][i] != '\0'))
        {
            c = fgetc(fp);
            i++;
        }
        if (i == strlen(argv[1])) count++;
    }
    printf("['%s' search result] %d times found\n", argv[1], count);

    fclose(fp);
}