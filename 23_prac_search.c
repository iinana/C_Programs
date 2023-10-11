#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

    char word[50];
    int i = 0, count = 0;

    int break_point = 1;
    while (break_point)
    {
        i = 0;
        while (((word[i] = tolower(fgetc(fp))) != EOF) && isalpha(word[i])) i++;

        if (word[i] == EOF) break_point = 0;
        word[i] = '\0';
        
        if (strstr(word, argv[1]) != NULL)
        {
            count++;
            printf("word includes '%s' : %s\n", argv[1], word);
        }
    }

    printf("-----------------------------------------------------------\n");
    printf("['%s' search result] %d times found\n", argv[1], count);
    
    fclose(fp);
}