#include <stdio.h>

/* string literal */
void literal(void);

/* make function using string */
void copy_str(char *origin, char *copy);
void combine_str(char *str1, char *str2);
int compare_str(char *str1, char *str2);

int main()
{
    /* copy string */
    char str1[] = "hello";
    char str2[] = "hi";
    printf("before copying : %s\n", str1);

    copy_str(str1, str2);
    printf("after copying : %s\n", str2);
    printf("\n");

    /* combine two strings */
    char str3[100] = "hello my name is ";
    char str4[] = "Psi";
    printf("before combining : %s\n", str3);

    combine_str(str3, str4);
    printf("after combining : %s\n", str3);
    printf("\n");

    /* compare two strings */
    char str5[] = "Psi";
    char str6[] = "hello your name?";

    if (compare_str(str4, str5)) printf("'%s' and '%s' are same\n", str4, str5);
    else printf("'%s' and '%s' are different\n", str4, str5);

    if (compare_str(str3, str6)) printf("%s and %s are same\n", str3, str6);
    else printf("'%s' and '%s' are different\n", str3, str6);

    return 0;
}

void literal(void)
{
    char str[] = "sentence";
    const char *pstr = "sentence";
    // pstr[0] = 'a'  // error 

    printf("str : %s\n", str);
    printf("pstr : %s\n", pstr);
}

void copy_str(char *origin, char *copy)
{
    int i = 0;
    while (copy[i])
    {
        origin[i] = copy[i];
        i++;
    }
    origin[i] = '\0';
}

void combine_str(char *str1, char *str2)
{
    int i = 0;
    while (str1[i]) i++;
    
    int k = 0;
    while (str2[k])
    {
        str1[i] = str2[k];
        i++;
        k++;
    }
    str1[i] = '\0';
}

int compare_str(char *str1, char *str2)
{
    while ((*str1) && (*str2))
    {
        if (*str1 != *str2) break;
        str1++;
        str2++;
    }
    if (*str1 || *str2) return 0;
    else return 1;
}