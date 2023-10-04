#include <stdio.h>

/* practice */
void prac_1(void);
void prac_2(void);
void prac_3(void);
void prac_4(void);
void prac_5(void);
void prac_6(void);
void prac_7(void);

int main()
{
    prac_7();
    return 0;
}


void prac_1(void)
{
    int n, i, k;
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (k = 0; k < (n-i); k++) printf(" ");
        for (k = 0; k < (2*i-1); k++) printf("*");
        printf("\n");
    }
}

void prac_2(void)
{
    int n, i, k;
    scanf("%d", &n);

    for (i = n; i > 0; i--)
    {
        for (k = 0; k < (n-i); k++) printf(" ");
        for (k = 0; k < (2*i-1); k++) printf("*");
        printf("\n");
    }
}

void prac_3(void)
{
    int sum = 0;
    for (int i = 1; i <= 1000; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0)) sum += i;
    }
    printf("%d", sum);
}

void prac_4(void)
{
    unsigned int gra, par, cur = 0;
    unsigned int i = 1, sum = 0;

    while (1)
    {   
        if (i == 1) cur = 1;
        else if (i == 2) cur = 2;
        else cur = gra + par;
        printf("%u ", cur);

        if (cur > 4000000) break;
        else
        {
            if (cur % 2 == 0) sum += cur;
            if (i != 1) gra = par;
            par = cur;

            i++;
        }
    }
    printf("\n%u", sum);
}

void prac_5(void)
{
    int n, res = 1;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) res *= i;
    printf("%d", res);
}

void prac_6(void)
{
    int count = 0;
    int a, b, c;
    for (a = 1; a < 1999; a++)
    {
        for (b = 1; b < 1999; b++)
        {
            if ((a+b) >= 2000) break;
            for (c = 1; c < 1999; c++)
            {
                if ((a+b+c == 2000) && (a > b) && (b > c)) count++;
            }
        }
    }
    printf("%d", count);
}

void prac_7(void)
{
    int n, count = 0;
    printf("N = ");
    scanf("%d", &n);
    printf("%d = ", n);

    int origin = n;
    for (int i = 2; i < origin; i++)
    {
        while (n % i == 0)   
        {
            printf("%d ", i);

            n /= i;
            if (n != 1) printf("* ");
        }
        if (n == 1) break;
    }
}