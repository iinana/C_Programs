#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Correct Usage : [program] [word to find]");
        return 0;
    }

    FILE *fp = fopen("a.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to open file");
        return 0;
    }

    char c;
    char data[40];
    int line = 1, count = 0;
    int i;
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '\n') line++;
        if (c == argv[1][0])
        {
            fseek(fp, -1, SEEK_CUR);
            fscanf(fp, "%s", data);
            if (strstr(data, argv[1]) != NULL)
            {
                count++;
                printf("%s is in line %d\n", argv[1], line);
            }
        }
    }
    fclose(fp);

    printf("[RESULT]----------------------------------------------------\n");
    printf("total %d number of '%s' are found\n", count, argv[1]);
}