#include <stdio.h>

void ary_basic(void);
void print_ary(void);
void ex_score(void);

void prac_1(void);
void prac_2(void);
void prac_2_upgrade(void);

int main()
{
    prac_2_upgrade();
    return 0;
}

void ary_basic(void)
{
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Third element of array1: %d\n", arr1[2]);

    int arr2[] = {1, 2, 3, 4};
    printf("Second element of array2: %d\n", arr2[1]);
}

void print_ary(void)
{
    int ary[10] = { 2, 10, 30, 21, 34, 23, 53, 21, 9, 1 };

    for (int i = 0; i < 10; i++) printf("array element %d : %d\n", (i+1), ary[i]);
}

void ex_score(void)
{
    int ary[5];
    int tot = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Score of Student %d : ", (i+1));
        scanf("%d", &ary[i]);
        tot += ary[i];
    }
    printf("Average of Students : %d\n", tot/5);
}

/* 성적을 입력받고 평균보다 높은 사람은 합격 출력 */
void prac_1(void)
{
    int ary[10];
    int tot = 0, avg, i;

    for (i = 0; i < 10; i++)
    {
        printf("Score of Student %d: ", (i+1));
        scanf("%d", &ary[i]);
        tot += ary[i];
    }

    avg = tot / 10;
    printf("Average of Students : %d\n", avg);

    for (i = 0; i < 10; i++)
    {
        printf("Student %d : ", (i+1));
        printf("%s", (ary[i] > avg) ? "Pass\n" : "Fail\n");
    }
}

/* Find prime number */
void prac_2(void)
{
    int i = 1;
    int count = 0;
    int res;

    while (1)
    {
        if ((i == 2) || (i == 3))
        {
            printf("Prime Number %d\n", i);
            count++;
        }
        else if (i % 2 != 0)
        {   
            res = 1;
            for (int k = 2; k < i; k++)
            {
                if (i % k == 0)
                {
                    res = 0;
                    break;
                }
            }
            
            if (res == 1)
            {
                printf("Prime Number %d\n", i);
                count++;
            }
        }
        if (count > 1000) break;
        i++;
    }
}

void prac_2_upgrade(void)
{
    int guess = 5;
    int prime[1000] = { 2, 3 };
    int count = 2;
    int i, res;

    while (1)
    {
        res = 1;
        for (i = 0; i < count; i++)
        {
            if (guess % prime[i] == 0)
            {
                res = 0;
                break;
            }
        }
        if (res == 1)
        {
            prime[count] = guess;
            count++;
        }
        guess++;

        if (count == 1000) break;
    }

    for (i = 0; i < 1000; i++) printf("Prime Number %d\n", prime[i]);
}