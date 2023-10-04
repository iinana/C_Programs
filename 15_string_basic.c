#include <stdio.h>
#include <string.h>

void null_char(void); // terminated string
void simple_str_pointer(void);
void change_str(void);
void count_num_of_str(void);
void input_string(void);
int prac_1(char *str1, char *str2);

int main()
{
    /* [15-1] practice number 3 */
    char str1[80], str2[80];
    printf("enter first string : ");
    scanf("%s", str1);
    printf("enter second string : ");
    scanf("%s", str2);

    int res = prac_1(str1, str2);
    printf("Two strings are %s", (res == 1) ? "same" : "different");
    return 0;
}

void null_char(void)
{
    char sentence_1[4] = {'P', 's', 'i', '\0'};
    char sentence_2[4] = {'P', 's', 'i', 0};
    //char sentence_3[4] = {'P', 's', 'i', (char)NULL};
    char sentence_4[4] = {"Psi"};

    printf("sentence_1 : %s\n", sentence_1);
    printf("sentence_2 : %s\n", sentence_2);
    //printf("sentence_3 : %s\n", sentence_3);
    printf("sentence_4 : %s\n", sentence_4);
}

void simple_str_pointer(void)
{
    char word[30] = {"long sentence"};
    char *str = word;

    printf("%s\n", str);
}

void change_str(void)
{
    char word[] = "long sentence";
    printf("Before changing : %s\n", word);

    word[0] = 'a';
    word[1] = 'b';
    word[2] = 'c';
    word[3] = 'd';

    printf("After changing : %s\n", word);
}

void count_num_of_str(void)
{
    char str[] = {"What is your name?"};

    int i = 0;
    while (str[i]) i++;  // while (str[i] != '\0')
    printf("Length of this string : %d\n", i);
}

void input_string(void)
{
    char str[30];
    printf("enter string less than 30 : ");
    
    scanf("%s", str);
    printf("String : %s\n", str);
}

int prac_1(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] && str2[i])
    {
        if (str1[i] != str2[i]) break;
        i++;
    }
    if (str1[i] || str2[i]) return 0;
    else return 1;
}