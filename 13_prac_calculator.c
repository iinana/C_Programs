#include <stdio.h>
#include <math.h>
#include <string.h>

int sorting(char *fomula, double *nums, char *signs, int *open, int *close, int len, int *bracket_loc, int *sign_loc);
double making_num(int *loc, char *fomula);
void find_bracket(int bracket_loc, int *open, int *close, double *nums, char *signs);
void calculate(int open, int close, double *nums, char *signs);
double operation(double num1, double num2, char sign);

int main()
{
    char fomula[80];
    scanf("%s", fomula);
    int len = strlen(fomula);

    double nums[40];
    int open[20], close[20];
    char signs[40];
    int bracket_loc = 0, sign_loc = 0;

    sorting(fomula, nums, signs, open, close, len, &bracket_loc, &sign_loc);
    find_bracket(bracket_loc, open, close, nums, signs);
    calculate(0, sign_loc, nums, signs);

    printf("= %f", nums[sign_loc]);
    return 0;
}

int sorting(char *fomula, double *nums, char *signs, int *open, int *close, int len, int *bracket_loc, int *sign_loc)
{
    int num_loc = 0, close_loc = 0;
    int i = 0;
    while (i < len)
    {
        if ((fomula[i] >= 48) && (fomula[i] <= 57))
        {
            nums[num_loc] = making_num(&i, fomula);
            num_loc++;
        }
        else 
        {
            if (fomula[i] == '(')
            {
                open[*bracket_loc] = *sign_loc;
                ++*bracket_loc;
            }
            else if (fomula[i] == ')')
            {
                close[close_loc] = *sign_loc - 1;
                close_loc++;
            }
            else 
            {
                signs[*sign_loc] = fomula[i];
                ++*sign_loc;
            }
            i++;
        }
    }
}

double making_num(int *loc, char *fomula)
{
    int int_part[40];
    double dec_part[40];
    int i = 0;
    while ((fomula[*loc] >= 48) && (fomula[*loc] <= 57))
    {
        int_part[i] = fomula[*loc] - 48;
        ++*loc;
        i++;
    }

    int num_len = i - 1;
    double num = 0, powing;
    for (int j = 0; j < i; j++)
    {
        powing = 1;
        for (int k = 0; k < num_len; k++) powing *= 10;
        num += (int_part[j] * powing);
        num_len--;
    }

    if (fomula[*loc] == '.')
    {
        i = 0;
        ++*loc;
        while ((fomula[*loc] >= 48) && (fomula[*loc] <= 57))
        {
            dec_part[i] = fomula[*loc] - 48;
            i++;
            ++*loc;
        }

        for (int j = 0; j < i; j++)
        {
            powing = 1;
            for (int k = 0; k < (j+1); k++) powing *= 10;
            num += (dec_part[j] / powing);
            num_len--;
        }
    }
    return num;
}

void find_bracket(int bracket_loc, int *open, int *close, double *nums, char *signs)
{
    int i, j, k;
    for (i = 0; i < bracket_loc; i++)
    {
        j = 0;
        while ((j < bracket_loc) && (open[j] <= close[i])) j++;
        j--;
        while (open[j] == -1) j--;
        calculate(open[j], close[i], nums, signs);
        open[j] = -1;
    }
}

void calculate(int open, int close, double *nums, char *signs)
{
    int i, j;
    for (i = open; i <= close; i++)
    {
        if ((signs[i] == '*') || (signs[i] == '/'))
        {
            j = i;
            do {j++;} while (nums[j] == -1);
            nums[j] = operation(nums[i], nums[j], signs[i]);
            nums[i] = -1;
            signs[i] = '!';
        }
    }
    for (i = open; i <= close; i++)
    {
        if ((signs[i] == '+') || (signs[i] == '-'))
        {
            j = i;
            do {j++;} while (nums[j] == -1);
            nums[j] = operation(nums[i], nums[j], signs[i]);
            nums[i] = -1;
            signs[i] = '!';
        }
    }
}

double operation(double num1, double num2, char sign)
{
    if (sign == '+') return num1 + num2;
    else if (sign == '-') return num1 - num2;
    else if (sign == '*') return num1 * num2;
    else if (sign == '/') return num1 / num2;
}