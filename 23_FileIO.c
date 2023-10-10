#include <stdio.h>

void output_to_file(void);

void input_from_file(void);
void input_one_by_one(void);

void position_indicator_input(void);
void position_indicator_output(void);

int main()
{
    position_indicator_output();
    return 0;
}

void output_to_file(void)
{
    FILE *fp;
    fp = fopen("./C_Start_3/a.txt", "w");
    if (fp == NULL)
    {
        printf("Write Error!!\n");
        return;
    }
    fputs("Hello World!!\n", fp);
    
    fclose(fp);
}

void input_from_file(void)
{
    FILE *fp;
    fp = fopen("./C_Start_3/a.txt", "r");

    char buf[20];

    if (fp == NULL)
    {
        printf("READ ERROR!!\n");
        return;
    }
    fgets(buf, 20, fp);  // fgets(variable to input, length to input, file);
    fclose(fp);

    printf("inputted content : %s\n", buf);
}

void input_one_by_one(void)
{
    FILE *fp;
    fp = fopen("./C_Start_3/a.txt", "r");
    char c;
    int size = 0;

    while ((c = fgetc(fp)) != EOF) 
    {
        printf("%c", c);
        size++;
    }
    printf("\n");
    fclose(fp);

    printf("size of the file : %d bytes\n", size);
}

void position_indicator_input(void)
{
    FILE *fw = fopen("./C_Start_3/a.txt", "w");
    if (fw == NULL)
    {
        printf("Write Error!!\n");
        return;
    }
    fputs("abcdef\n", fw);
    fclose(fw);

    FILE *fp = fopen("./C_Start_3/a.txt", "r");
    printf("%c", fgetc(fp));
    printf("%c", fgetc(fp));
    printf("%c", fgetc(fp));
    printf("%c", fgetc(fp));
    printf("\n");
    /* input by d, and want to go back to a (originally go to e)*/

    fseek(fp, 0, SEEK_SET);
    // 0th location from SEEK_SET (macro constant of file's first)
    // other macro constant : SEEK_CUR (current location), SEEK_END (file's end)

    printf("Go back to first char :%c\n", fgetc(fp));
    fclose(fp);
}

void position_indicator_output(void)
{
    FILE *fp = fopen("./C_Start_3/a.txt", "w");
    fputs("Psi is an excellent C programmer\n", fp);
    fseek(fp, 0, SEEK_SET);
    fputs("is Psi", fp);
    fclose(fp);
}