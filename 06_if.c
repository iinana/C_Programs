#include <stdio.h>

void if_basic(void);
void ex_division(void);
void ex_passfail(void);
void ex_pf_upgrade(void);
void ex_comparing(void);

/* Logical Operator */
void Logical_AND(void);
void Logical_OR(void);



int main()
{
    Logical_OR();
    return 0;
}

void if_basic(void)
{
    int i;
    printf("enter one integer: ");
    scanf("%d", &i);

    if (i == 7) printf("you entered a lucky number");
    else if (i == 4) printf("you entered num of death");
    else printf("you entered %d", i);
}

void ex_division(void)
{
    double i, j;
    printf("enter two integer to divide: ");
    scanf("%lf%lf", &i, &j);

    if (j == 0) printf("you can't divide by 0");
    else printf("%f / %f = %f", i, j, i/j);
}

void ex_passfail(void)
{
    int score;
    printf("enter your math score: ");
    scanf("%d", &score);

    if (score >= 90) printf("Pass");
    else printf("Fail");
}

void ex_pf_upgrade(void)
{
    double mat, eng, sci, pro, avg;
    printf("enter your math, english, science, programming score: ");
    scanf("%lf%lf%lf%lf", &mat, &eng, &sci, &pro);

    avg = (mat + eng + sci + pro) / 4;
    printf("Your average score is %f\n", avg);

    if (avg >= 90) printf("Excellent");
    else if (avg >= 40) printf("Good");
    else printf("Fail");
}

void ex_comparing(void)
{
    int num;
    printf("enter a number: ");
    scanf("%d", &num);

    if ((num >= 10) && (num < 20)) printf("%d is over than 10 and less than 20", num);
}

void Logical_AND(void)
{
    int a = 31, b = 15;
    printf("a & b = %d\n", a&b); // result of logical multiplication
    printf("a && b = %d\n", a&&b);  // boolean result (logical operator)
}

void Logical_OR(void)
{
    int hei, wei;
    printf("enter you height and weight: ");
    scanf("%d%d", &hei, &wei);

    if (hei >= 190 || wei >= 100) printf("you are a giant person");
    if (!(hei >= 190 || wei >= 100)) printf("you are not a giant person");
}

