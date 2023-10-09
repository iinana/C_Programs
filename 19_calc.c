#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if (argc != 4) 
    {
        printf("Correct Usage : [program] [num1] [sign] [num2]\n"); 
        exit(1);
    }

    char sign = argv[2][0];
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[3]);
    int res;

    if (sign == '+') res = n1 + n2;
    else if (sign == '-') res = n1 - n2;
    else if (sign == 'x') res = n1 * n2;
    else if (sign == '/') res = n1 / n2;
    else
    {
        printf("Correct Sign : +, -, x, /\n");
        exit(1);
    }

    printf("%d\n", res);
}