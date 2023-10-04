#include <stdio.h>

/* [15-3] practice num1 */
void prac_1(void);
void reverse(char *str);

/* [15-3] practice number 2 */
void prac_2(void);
void scale_convert(char *str);

/* [15-3] practice number 4 */
void prac_4(void);
int search(char *str1, char *str2);

int main()
{
    prac_4();
    return 0;
}

/* [15-3] practice num1 */
void prac_1(void)
{
    char str[100];
    printf("enter a string : ");
    scanf("%s", str);

    reverse(str);
}

void reverse(char *str)
{
    int i = 0;
    while (str[i]) i++;
    while (i > 0)
    {
        i--;
        printf("%c", str[i]);
    }
}


/* [15-3] practice number 2 */
void prac_2(void)
{
    char str[100];
    printf("enter a string : ");
    scanf("%s", str);

    scale_convert(str);
    printf("%s\n", str);
}

void scale_convert(char *str)
{
    while (*str)
    {
        if ((*str >= 65) && (*str <= 90)) *str += 32;
        else *str -= 32;

        str++;
    }
}


/* [15-3] practice number 4 */
void prac_4(void)
{
    char str1[] = "I_am_a_boy";
    char str2[50];

    printf("I want to find... ");
    scanf("%s", str2);

    int loc = search(str1, str2);
    if (loc == -1) printf("No result");
    else printf("%s is at %d", str2, loc);
}

int search(char *str1, char *str2)
{
    int i = 0, k = 0;
    while (str1[i])
    {
        if (str1[i] == str2[k])
        {
            while (str2[k])
            {
                str1++;
                k++;
                if (str1[i] != str2[k]) break;
            }
            if (str2[k] == '\0') return i;
        }
        i++;
    }
}