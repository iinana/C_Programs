#include <stdio.h>
#include <string.h>
#include <math.h>

void trans_radix(int from, int to, char *num, char *res, int len);
int to_deci(char *num, int from, int len);
void to_char(int dec, char *res);
void to_bin_oct(int dec, int to, char *res);
void to_hexa(int dec, char *res);

int main()
{
    int from, to;
    char num[80];
    printf("Enter a Number : ");
    scanf("%s", num);
    printf("Enter the original Radix of number : ");
    scanf("%d", &from);
    printf("Enter the radix which you want to transfer to : ");
    scanf("%d", &to);

    int len = strlen(num);
    char res[80];
    trans_radix(from, to, num, res, len);
    printf("%s => %s", num, res);
    return 0;
}

void trans_radix(int from, int to, char *num, char *res, int len)
{
    int dec = to_deci(num, from, len);

    if (to == 10) to_char(dec, res);
    else if (to == 16) to_hexa(dec, res);
    else to_bin_oct(dec, to, res);
}

int to_deci(char *num, int from, int len)
{
    int res = 0;
    int j = len - 1;
    int i;
    if (from == 16)
    {
        int n;
        for (i = 0; i < len; i++)
        {
            n = num[i];
            if ((n >= 65) && (n <= 70)) n -= 55;
            else n -= 48;

            if (j == 0) res += n;
            else res += n * pow(from, j);
            j--;
        }
    }
    else if (from == 10)
    {
        int powing;
        for (i = 0; i < len; i++)
        {
            powing = 1;
            for (int k = 1; k <= j; k++) powing *= 10;
            res += powing * (num[i] - 48);
            j--;
        }
    }
    else
    {
        for (i = 0; i < len; i++)
        {
            if (j == 0) res += (num[i] - 48);
            else res += (num[i] - 48) * pow(from, j);
            j--;
        }
    }
    return res;
}

void to_char(int dec, char *res)
{
    int loc = 1;
    while ((dec / loc) >= 10) loc *= 10;

    int n, i = 0;
    while (loc >= 1)
    {
        n = (int)(dec / loc);
        res[i] = n + 48;
        dec -= n * loc;
        loc /= 10;
        i++; 
    }
    res[i] = '\0';
}

void to_bin_oct(int dec, int to, char *res)
{
    int count = 0;
    int loc = 1;
    while (dec > loc)
    {
        count++;
        loc = pow(to, count);
    }

    int n;
    for (int i = 0; i < count; i++)
    {
        loc /= to;
        if (dec >= loc)
        {
            n = dec / loc;
            res[i] = n + 48;
            dec -= n * loc;
        }
        else res[i] = '0';
    }
    res[count] = '\0';
}

void to_hexa(int dec, char *res)
{
    int count = 0;
    int loc = 1;
    while (dec > loc)
    {
        count++;
        loc = pow(16, count);
    }

    int n;
    for (int i = 0; i < count; i++)
    {
        loc /= 16;
        if (dec >= loc)
        {
            n = dec / loc;
            res[i] = (n < 10) ? (n + 48) : (n + 55);
            dec -= n * loc;
        }
        else res[i] = '0';
    }
    res[count] = '\0';
}