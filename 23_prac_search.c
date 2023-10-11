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

    int i = 0;

    char c;
    int count = 0, word_count = 0;
    
    while ((c = fgetc(fp)) != EOF)
    {
        i = 0;
        word_count++;
        if (c == ' ') word_count = 0;
        while ((tolower(c) == argv[1][i]) && (argv[1][i] != '\0'))
        {
            c = fgetc(fp);
            word_count++;
            i++;

            if (c == ' ')
            {
                word_count = 0;
                break;
            }
        }
        if (i == strlen(argv[1])) 
        {
            count++;
            printf("word_count includes '%s' : ", argv[1]);
            fseek(fp, -word_count, SEEK_CUR);
            while((c = fgetc(fp)) != ' ') 
            {
                if (!isalpha(c)) break;
                printf("%c", c);
            }
            printf("\n");
        }
    }
    printf("-----------------------------------------------------------\n");
    printf("['%s' search result] %d times found\n", argv[1], count);

    fclose(fp);
}