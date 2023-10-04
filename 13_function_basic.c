#include <stdio.h>

int prac_1(int num);
int prac_2(int curr, int income);
int prac_3(int n);
int prac_4(int n);
void prac_5(int n);

int main()
{
    printf("x + 4 : %d\n", prac_1(36));
    printf("current property : %d\n", prac_2(1000, 100));
    printf("sum of 1 to n : %d\n", prac_3(10));
    printf("number of prime number from 1 to n : %d\n", prac_4(10));
    prac_5(26);
    return 0;
}

int prac_1(int num)
{
    return num + 4;
}

int prac_2(int curr, int income)
{
    return curr+income;
}

int prac_3(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += i;
    return sum;
}

int prac_4(int n)
{
    int count = 2;
    int res;
    for (int i = 5; i <= n; i += 2)
    {
        res = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0) res = 0;
        }
        if (res == 1) count++;
    }

    return count;
}

void prac_5(int n)
{
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            printf("%d ", i);
            n /= i;
            if (n == 1) break;
            else printf("X ");
        }
        if (n == 1) break;
    }
}