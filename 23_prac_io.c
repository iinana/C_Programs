#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fa = fopen("./C_Start_3/a.txt", "r");
    FILE *fb = fopen("./C_Start_3/b.txt", "w");

    if ((fa == NULL) || (fb == NULL)) 
    {
        printf("File Input Failed\n");
        exit(1);
    }

    char c;
    while ((c = fgetc(fa)) != EOF) fputc(c, fb);

    fclose(fa);
    fclose(fb);
}