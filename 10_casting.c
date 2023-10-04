#include <stdio.h>

void doulbe_to_int(void);
void int_to_float(void);

void prac(void);

int main()
{
    prac();
    return 0;
}

void double_to_int(void)
{
    int a;
    double b;

    b = 2.4;
    a = (int)b;

    printf("%d", a);
}

void int_to_float(void)
{
    int a, b;
    float c, d;

    printf("enter two numbers : ");
    scanf("%d%d", &a, &b);

    c =  a / b;
    d = (float)a / b;

    printf("ratio of two nums (without casting) : %f\n", c);
    printf("ratio of two nums (with casting) : %f\n", d);
}

void prac(void)
{
    float f;
    int i;
    printf("enter a real number : ");
    scanf("%f", &f);

    i = (f - (int)f) * 100;
    printf("i = %d", i);
}