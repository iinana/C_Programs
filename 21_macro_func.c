#include <stdio.h>

#define square(x) x*x   // #define func(argument) return
#define square2(x) (x)*(x)

#define RADTODEG(x) (x) * 57.295
#define RADTODEG2(x) ((x) * 57.295)

#define PrintVariableName(var) printf(#var "\n"); // '#' change something to string

#define AddName(x, y) x##y

int main()
{
    /* basic usage of macro function */
    printf("square(3) = %d\n", square(3));

    printf("square(3+1) = %d\n", square(3+1));    // = 3 + 1 * 3 + 1 = 7
    printf("square2(3+1) = %d\n", square2(3+1));  // = (3 + 1) * (3 + 1) = 16


    /* radian degree calculation (caution about brackets)*/
    printf("5 rad : %f deg\n", RADTODEG(5));

    printf("1 / 5 rad : %f\n", 1/RADTODEG(5));  // 1 / 5 * 57.295
    printf("1 / 5 rad : %f\n", 1/RADTODEG2(5));


    /* how to print variable's name */
    int a = 3;
    PrintVariableName(a);
    return 0;

    int AddName(b, c);
    bc = 3;
    printf("%d", bc);
}