#include <stdio.h>

void char_var(void);

/* scanf function */
void scanf_basic(void);
void scanf_all(void);

int main()
{
    scanf_all();
    return 0;
}

void char_var(void)
{
    char a = 'a';

    printf("value of a = %c\n", a);
    printf("ASCII code of a = %d\n", a);
}

void scanf_basic(void)
{
    double celsius;

    printf("Program that changes 'Celsius' to 'Fahrenheit'\n");
    printf("enter the Celsius: ");
    scanf("%lf", &celsius);

    printf("Celsius %f degree is %f degree in Fahrenheit\n", celsius, (celsius * 9) / 5 + 32);
}

void scanf_all(void)
{
    /* character */
    char ch;
    printf("char type var input: ");
    scanf("%c", &ch);

    /* integer */
    short sh;
    printf("short type var input: ");
    scanf("%hd", &sh);

    int i;
    printf("int type var input: ");
    scanf("%d", &i);

    long lo;
    printf("long type var input: ");
    scanf("ld", &lo);

    /* real num */
    float fl;
    printf("float type var input: ");
    scanf("%f", &fl);

    double du;
    printf("double type var input: ");
    scanf("%lf", &du);


    printf("char : %c, short : %d, int : %d\n", ch, sh, i);
    printf("long : %ld, float: %f, double : %f\n", lo, fl, du);
}
