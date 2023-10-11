#include <stdio.h>
#include <string.h>

/* File Position Indicator */
void file_position_indicator(void);
void fseek_func(void);

/* The other arguments of fopen() func */
void Read_N_Write(void);  // Read and Write at the same time
void prac_scale_swap(void);
void append(void);  // append from the end of document

/* fscanf() function */
void fscanf_func(void);
void change_word(void);

int main()
{
    change_word();
    return 0;
}

void file_position_indicator(void)
{
    FILE *fp = fopen("./C_Start_3/a.txt", "r");
    char c;

    if (fp == NULL)
    {
        printf("file open error\n");
        return;
    }

    // if fgetc() is called, indicator moves one by one (make we can read file in order)
    while ((c = fgetc(fp)) != EOF) printf("%c", c);

    fclose(fp);
}

void fseek_func(void)
{
    FILE *fp = fopen("./C_Start_3/a.txt", "r");
    char data[10];
    char c;

    if (fp == NULL)
    {
        printf("file open error\n");
        return;
    }

    fgets(data, 5, fp);
    printf("data inputted : %s\n", data);

    c = fgetc(fp);
    printf("data inputted : %c\n", c);

    fseek(fp, -1, SEEK_CUR);
    c = fgetc(fp);
    printf("data after going back : %c\n", c);

    fseek(fp, -1, SEEK_END);
    c = fgetc(fp);
    printf("last letter : %c\n", c);

    fseek(fp, 0, SEEK_SET);
    c = fgetc(fp);
    printf("first letter : %c\n", c);

    fclose(fp);
}

void Read_N_Write(void)
{
    FILE *fp = fopen("./C_Start_3/a.txt", "r+");
    // if you use w+, the original file's content will be erased
    char data[100];

    fgets(data, 100, fp);
    printf("[Current Content] %s\n", data);

    fseek(fp, 0, SEEK_SET);
    fputs("There is nothing on this file", fp);

    fseek(fp, 0, SEEK_SET);
    fgets(data, 100, fp);
    printf("[After Writing] %s\n", data);

    fclose(fp);
}

void prac_scale_swap(void)
{
    FILE *fp = fopen("./C_Start_3/b.txt", "r+");
    if (fp == NULL)
    {
        printf("File reading failed\n");
        return;
    }

    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        if ((c >= 65) && (c <= 90)) 
        {
            fseek(fp, -1, SEEK_CUR);
            fputc((c+32), fp);
            fseek(fp, 0, SEEK_CUR);  // should call it, when you switch the mode (reading -> writing)
        }
        else if ((c >= 97) && (c <= 122))
        {
            fseek(fp, -1, SEEK_CUR);
            fputc((c-32), fp);
            fseek(fp, 0, SEEK_CUR);
        }
    }
    fclose(fp);
}

void append(void)
{
    FILE *fp = fopen("./C_Start_3/a.txt", "a");
    if (fp == NULL)
    {
        printf("Failed to open file\n");
        return;
    }
    
    fputs(" For sure it is good news.", fp);
    fclose(fp);
}

void fscanf_func(void)
{
    FILE *fp = fopen("./C_Start_3/a.txt", "r");
    char data[100];
    if (fp == NULL)
    {
        printf("Failed to open file");
        return;
    }

    printf("--------------------- Words inputted ---------------------\n");
    while (fscanf(fp, "%s", data) != EOF) printf("%s\n", data);
    fclose(fp);
}

void change_word(void)
{
    // Samsung to Company
    FILE *fp = fopen("./C_Start_3/b.txt", "r+");
    char data[30];
    int check;

    while (fscanf(fp, "%s", data) != EOF)
    {
        if (strcmp(data, "Samsung") == 0)
        {
            fseek(fp, -(long)strlen(data), SEEK_CUR);
            fputs("Company", fp);
            fseek(fp, 0, SEEK_CUR);
        }
    }
    fclose(fp);
}