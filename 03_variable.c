#include <stdio.h>

void int_var(void);
void real_var(void);
void many_use(void);


int main()
{
    many_use();

    return 0;
}


void int_ver(void)
{
    int a;
    a = 127;
    printf("value of a = %d\n", a);

    // other numerial expression
    printf("value of a with octal = %o\n", a);
    printf("value of a with hex = %x\n", a);
}

void real_var(void)
{
    float a = 3.141592f;  // without 'f', it can be reconized 'double' type => error
    double b = 3.141592;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
}

void many_use(void)
{
    float a = 3.141592f;
    double b = 3.141592;
    int c = 123;

    printf("a : %.2f\n", a);  // to two decimal point
    printf("c : %5d\n", c);  // with 5 amount of space
    printf("b : %6.3f\n", b); // with 6 amount of space && to three decimal point
}