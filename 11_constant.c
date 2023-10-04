#include <stdio.h>

void use_const(void);
void initialize_ary(void);

void prac_1(void);
void prac_2(int n, int *ordered);

int main()
{
    prac_1();
    return 0;
}

void use_const(void)
{
    const int a = 3;  // cannot change the value && must initialize
    printf("%d", a);
}

void initialize_ary(void)
{
    int arr[3] = {1};  // = { 1, 0, 0 }
    printf("%d", arr[2]);
}

/* make an order with student score */
void prac_1(void)
{
    int n;
    printf("Number of Students : ");
    scanf("%d", &n);

    int score[n];
    for (int i = 0; i < n; i++)
    {
        printf("score of stduent%d : ", (i+1));
        scanf("%d", &score[i]);
    }

    int ordered[n];
    int M_idx;
    for (int i = 0; i < n; i++)
    {
        M_idx = 0;
        for (int k = 1; k < n; k++)
        {
            if (score[k] > score[M_idx]) M_idx = k;
        }
        printf("%d : %d\n", (i+1), score[M_idx]);
        ordered[i] = score[M_idx];
        score[M_idx] = -1;
    }

    /* bar graph of students */
    prac_2(n, ordered);
}

void prac_2(int n, int *ordered)
{
    int gra;
    for (int i = 0; i < n; i++)
    {
        gra = ordered[i] / 5;
        printf("Student%3d: ", i);
        for (int k = 0; k < gra; k++)
        {
            printf("бс");
        }
        printf("\n");
    }
}