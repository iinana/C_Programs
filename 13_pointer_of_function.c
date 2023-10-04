#include <stdio.h>

int max(int a, int b);
int donothing(int a, int b);
int print_ary(int (*arr)[3], int row);

int main()
{
    int a, b;
    int (*pfunc)(int, int);  // function pointer
    pfunc = max;

    scanf("%d%d", &a, &b);
    printf("max(a, b) : %d\n", max(a, b));
    printf("pfunc(a, b) : %d\n", pfunc(a, b));

    pfunc = donothing;
    printf("donothing(a, b) : %d\n", donothing(a, b));
    printf("pfunc(a, b) : %d\n", pfunc(a, b));


    int arr[2][3] = {{0, 0, 0}, {1, 1, 1}};
    int (*par)(int(*)[3], int);
    par = print_ary;
    printf("print_ary(arr, 2) : %d\n", print_ary(arr, 2));
    printf("par(arr, 2) : %d\n", par(arr, 2));
}

int max(int a, int b)
{
    if (a > b) return a;
    else return b;
}

int donothing(int a, int b) {return 1;}

int print_ary(int (*arr)[3], int row)
{
    return arr[row-1][2];
}