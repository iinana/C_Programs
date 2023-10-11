#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AddLoc(x, y) x##y

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        printf("Correct Usage : [program] [file location]");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "w");
    fputc('a', fp);
    fclose(fp);
}