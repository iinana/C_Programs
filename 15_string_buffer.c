#include <stdio.h>

void clean_buffer_fflush(void);
void clean_buffer_getchar(void);

int main()
{
    clean_buffer_getchar();
    return 0;
}

void clean_buffer_fflush(void)
{
    int num;
    char c;

    printf("enter an integer : ");
    scanf("%d", &num);

    fflush(stdin);  // clean the stdin (a buffer)

    printf("enter a character : ");
    scanf("%c", &c);
}

void clean_buffer_getchar(void)
{
    int num;
    char c;

    printf("enter an integer : ");
    scanf("%d", &num);

    getchar();  // clean buffer (but if there are more than one data in buffer, it will clean only one)

    printf("enter a character : ");
    scanf("%c", &c);
}